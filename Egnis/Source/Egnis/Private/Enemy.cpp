// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "ActionDataAsset.h"
#include "EnemyArcheTypeDataAsset.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (!ArchetypeData)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Enemy has no ArchetypeData assigned (DA_Enemy_Warrior / DA_Enemy_Healer)."),
			*GetName());
		return;
	}
	for (const UActionDataAsset* Action : ArchetypeData->Actions)
	{
		if (!Action) continue;

		const FString ActionIdStr =
			(Action->ActionId == EActionId::Attack) ? TEXT("Attack") : TEXT("Heal");
	}

	if (bDebugMovementOnBeginPlay)
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle,this,&AEnemy::MoveTowardClosesPlayer,0.5f,false);
		
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AEnemy::MoveTowardClosesPlayer()
{
	if (!Board)
	{
		return;
	}

	ACharacterBase* Target = FindClosestPlayer();
	if (!Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] MoveTowardClosestPlayer_2Tiles: No player found"), *GetName());
		return;
	}

	const FTileCoord Start = CurrentTile;
	const FTileCoord Goal = Target->CurrentTile;

	// Candidatas: 4 direcciones rectas
	const FIntPoint Dirs[4] = {
		FIntPoint( 1,  0), // derecha
		FIntPoint(-1,  0), // izquierda
		FIntPoint( 0,  1), // arriba 
		FIntPoint( 0, -1)  // abajo
	};

	bool bFoundDir = false;
	FIntPoint BestDir (0,0);
	int32 BestDist = ManhattanDistance(Start,Goal);

	// 1) Elegir dirección óptima (según la casilla final tras 2 pasos)

	for (const FIntPoint& Dir : Dirs)
	{
		const FTileCoord Step1(Start.X + Dir.X, Start.Y + Dir.Y);
		const FTileCoord Step2(Start.X + 2 * Dir.X, Start.Y + 2 * Dir.Y);

		//Debe poder dar 2 pasos
		if (!Board->IsInside(Step1) || !Board->IsInside(Step2))
		{
			continue;
		}

		//Deben de estar libres los 2 pasos
		if (Board->IsTileOccupied(Step1) || Board->IsTileOccupied(Step2))
		{
			continue;
		}

		const int32 DistToGoal = ManhattanDistance(Step2, Goal);
		if (DistToGoal < BestDist)
		{
			BestDist = DistToGoal;
			BestDir = Dir;
			bFoundDir = true;
		}
	}
	if (!bFoundDir)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] No tenemos camino valido  o no nos acercar al enemigo."), *GetName());
		return;
	}

	//Ejecutar Paso 1
	const FTileCoord FirstStep(Start.X + BestDir.X, Start.Y + BestDir.Y);

	if (!SetCurrentTile(FirstStep))
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Failed to move to Step1."), *GetName());
		return;
	}

	SetActorLocation(Board->TileToWorldCenter(CurrentTile));

	//Re-comprobar y ejecutar paso 2 (MISMA dirección del origen)
	const FTileCoord SecondStep(Start.X + 2 * BestDir.X, Start.Y + 2 * BestDir.Y);

	
	// Nota: SecondStep está definido respecto al Start (origen), por la regla de “misma dirección originaria”
	if (!Board->IsInside(SecondStep) || Board->IsTileOccupied(SecondStep))
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Step2 blocked after Step1. Stops at (%d,%d)."),
			*GetName(), CurrentTile.X, CurrentTile.Y);
		
		SetActorLocation(Board->TileToWorldCenter(CurrentTile));
		return;
	}
	if (!SetCurrentTile(SecondStep))
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] Failed to move to Step2. Stops at (%d,%d)."),
			*GetName(), CurrentTile.X, CurrentTile.Y);

		SetActorLocation(Board->TileToWorldCenter(CurrentTile));
		return;
	}

	SetActorLocation(Board->TileToWorldCenter(CurrentTile));

	UE_LOG(LogTemp, Log, TEXT("[%s] Moved 2 tiles straight to (%d,%d) towards player (%d,%d)."),
		*GetName(), CurrentTile.X, CurrentTile.Y, Goal.X, Goal.Y);
}

void AEnemy::MakeAction()
{
}


ACharacterBase* AEnemy::FindClosestPlayer() const
{
	TArray<AActor*> Found;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacterBase::StaticClass(), Found);

	ACharacterBase* Best = nullptr;
	int32 BestDist = TNumericLimits<int32>::Max();

	for (AActor* Actor : Found)
	{
		ACharacterBase* Target = Cast<ACharacterBase>(Actor);
		if (!Target) continue;
		if (Target == this) continue;

		if (Target->GetTeam() != 0) continue;

		const int32 Dist = ManhattanDistance(Target->CurrentTile, CurrentTile);
		if (Dist < BestDist)
		{
			BestDist = Dist;
			Best = Target;
		}
	}

	return Best;
	
}

int32 AEnemy::ManhattanDistance(const FTileCoord& A, const FTileCoord& B)
{
	return FMath::Abs(A.X - B.X) + FMath::Abs(A.Y - B.Y);
}

const UActionDataAsset* AEnemy::GetActionById(EActionId ActionId) const
{
	if (!ArchetypeData)
	{
		return nullptr;
	}

	for (const UActionDataAsset* Action : ArchetypeData->Actions)
	{
		if (Action && Action->ActionId == ActionId)
		{
			return Action;
		}
	}
	return nullptr;
}
