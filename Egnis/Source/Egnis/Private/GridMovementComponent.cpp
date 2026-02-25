// Fill out your copyright notice in the Description page of Project Settings.


#include "GridMovementComponent.h"
#include "Engine.h"
#include"Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UGridMovementComponent::UGridMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UGridMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	EnsureBoardActor();
	if (!BoardActor) return;

	FTileCoord StartTile;
	if (getCurrentTile(StartTile))
	{
		// Ocupamos la casilla inicial
		BoardActor->SetTileOccupant(StartTile, GetOwner());
	}
}

void UGridMovementComponent::EnsureBoardActor()
{
	if (BoardActor)
	{
		return;
	}
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoard::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		BoardActor=Cast<ABoard>(FoundActors[0]);//

		UE_LOG(LogTemp,Warning, TEXT("Tablero asignado:%s"),*GetNameSafe(BoardActor));

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Tablero"));
		}

	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("No se ha encontrado ningun tablero"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red,TEXT("No se ha encontrado tablero"));
				
		}
	}
}

//comprueba casilla si esta dentro del tablero 
bool UGridMovementComponent::IsTileValid(const FTileCoord& T)
{
	if (!BoardActor)
	{
		return false;
	}

	return (T.X >= 0 && T.X < BoardActor->BoardSizeX && T.Y >= 0 && T.Y < BoardActor->BoardSizeY);
}


//calcula la actual
bool UGridMovementComponent::getCurrentTile(FTileCoord& OutTile)
{
	if (!BoardActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("No hay BoardActor asignado"));
		return false;
	}

	return BoardActor->WorldPointToTile(GetOwner()->GetActorLocation(), OutTile);
}

//devuelve tods las casillas a las que se puede mover (8 dir hasra rango)
void UGridMovementComponent::getRachableTiles(TArray<FTileCoord>& OutTiles)
{
	OutTiles.Reset();//.Empty();

	EnsureBoardActor();

	if (!BoardActor)
	{
		UE_LOG(LogTemp, Error, TEXT("No hay tablero asignado"));
		return;
	}
	FTileCoord CurrentTile;
	if (!getCurrentTile(CurrentTile))
	{
		UE_LOG(LogTemp, Warning, TEXT("No se pudo obtener la casilla actual"));
		return;
	}

	//definicion de 8 dir 
	const TArray<FTileCoord> Directions = {
		{1, 0}, {1, 1}, {0, 1}, {-1, 1},
		{-1, 0}, {-1, -1}, {0, -1}, {1, -1}
	};

	for (const FTileCoord& Dir : Directions)
	{
		for (int32 Step = 1; Step <= moveRange; ++Step)
		{
			FTileCoord Target = { CurrentTile.X + Dir.X * Step, CurrentTile.Y + Dir.Y * Step };
			if (IsTileValid(Target))
			{

				//meter sist blqueos u obstaculos
				/*if(IsTileBlocked(Target)){
				 *break;
				 *}
				 **/
				//si la casilla esta ocupada ,no se mueve
				AActor* Occupant = BoardActor->GetTileOccupant(Target);

				if (Occupant && Occupant != GetOwner())
				{
					//bloquea el movimiento en esta direccion
					break;//en caso de no bloquear cambiar por continue;
				}
				
				OutTiles.Add(Target);
				
			}
			else
			{
				break;
			}
		}
	}
}

bool UGridMovementComponent::canMoveToTile(const FTileCoord& Target)
{
	if (!BoardActor)
	{
		EnsureBoardActor();
	}

	if (!BoardActor)
	{
		return false;
	}
	if (!IsTileValid(Target))
	{
		return false;
	}

	//si casilla esta ocupada no se puede mover
	AActor* Occupant = BoardActor->GetTileOccupant(Target);
	if (Occupant && Occupant != GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("Casilla ocupada (%d,%d)"), Target.X, Target.Y);
		return false;
	}
	//obtiene las casillas a las que se puede mover
	TArray<FTileCoord> ReachableTiles;
	getRachableTiles(ReachableTiles);

	//comprueba si la casilla objetivo esta dentro
	for (const FTileCoord& Tile : ReachableTiles)
	{
		if (Tile.X == Target.X && Tile.Y == Target.Y)
		{
			return true;
		}
	}
	return false;
}

bool UGridMovementComponent::moveToTile(const FTileCoord& Target)
{
	EnsureBoardActor();

	if (!BoardActor)
	{
		return false;
	}

	//comprueba limites
	if (!IsTileValid(Target))
	{
		UE_LOG(LogTemp, Warning, TEXT("Casilla invalida (%d,%d)"), Target.X, Target.Y);
		return false;
	}

	//comprueba que esta dentro del patron 
	if (!canMoveToTile(Target))
	{
		UE_LOG(LogTemp, Warning, TEXT("Movimiento no permitido a (%d,%d)"), Target.X, Target.Y);
		return false;
	}
	

	//casilla a pos en juego
	FVector Destination = BoardActor->TileToWorldCenter(Target);

	/*
	 *Actualizar sist de ocupacion de casillas del tablero
	 *liberar casilla anterior
	 * marcar casilla nueva como ocupada
	 */
	//guarda la casilla anterior para liberar
	FTileCoord OldTile;
	const bool bHasOldTile = getCurrentTile(OldTile);
	//mover actor
	GetOwner()->SetActorLocation(Destination);

	//actualiza ocupacion del tablero
	if (bHasOldTile)
	{
		BoardActor->SetTileOccupant(OldTile, nullptr);
	}
	BoardActor->SetTileOccupant(Target, GetOwner());
	UE_LOG(LogTemp, Log, TEXT("Unidad movida a (%d,%d)"), Target.X, Target.Y);

	return true;
}
