#include "BoardPlayerController.h"
#include "BattleManager.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "DrawDebugHelpers.h"
#include "Board.h"
#include "CharacterBase.h"
#include "GameManager.h"

ABoardPlayerController::ABoardPlayerController()
{
	bShowMouseCursor = true;
	//bEnableClickEvents = true;
	//bEnableMouseOverEvents = true;
}

void ABoardPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);
	
	// Obtener sistema que gestiona el InputMappingContext
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (IMCGameplay)
				Subsystem->AddMappingContext(IMCGameplay, 0);
			if (IMCUI)
				Subsystem->AddMappingContext(IMCUI, 1);	// Mayor prioridad
		}
	}
	
	// Referencia al GameManager
	if (AGameManager* GM = Cast<AGameManager>(GetWorld()->GetAuthGameMode()))
	{
		BM = GM->GetBattleManager();
	}

	if (!BM)
	{
		UE_LOG(LogTemp, Error, TEXT("BoardPlayerController: BattleManager is null"));
	}
}

// Asignar controles
void ABoardPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	if (!EnhancedInput) return;
	//check(EnhancedInput);

	//check(ClickAction);
	if (!ClickAction || !PauseAction)
	{
		UE_LOG(LogTemp, Warning, TEXT("ClickAction or PauseAction not found"));
		return;
	}
	EnhancedInput->BindAction(ClickAction, 
		ETriggerEvent::Started, 
		this, 
		&ABoardPlayerController::HandleLeftClick
	);
	EnhancedInput->BindAction(
			PauseAction,
			ETriggerEvent::Started,
			this,
			&ABoardPlayerController::HandleMenu
	);
}

// Interacción con click izquierdo
void ABoardPlayerController::HandleLeftClick()
{
	if (bIsInMenu) return;
	
	FClickResult Result;

	const ECollisionChannel UnitChannel  = UnitTraceChannel;
	const ECollisionChannel BoardChannel  = BoardTraceChannel;

	FHitResult Hit;

	// ===== CONTROL DE ESTADOS DE JUEGO DE CARTAS =====
	// Comprobar que se esta jugando una carta (BeginPlayCard cambia el estado de None ECardSelectionState)
	if (SelectionState != ECardSelectionState::None)
	{
		// 1- Eligiendo unidad que juega la carta
		if (SelectionState == ECardSelectionState::SelectingUnit)
		{
			if (TraceUnderCursor(UnitChannel, Hit))
			{
				if (ACharacterBase* Character = Cast<ACharacterBase>(Hit.GetActor()))
				{
					if (Character->GetTeam() == 0)	// Solo se pueden seleccionar unidades aliadas para jugar cartas
					{
						PendingSource = Character;
						SelectionState = ECardSelectionState::SelectingTarget;
						Result.bHit = true;
						Result.bHitUnit = true;
						Result.HitActor = Hit.GetActor();
						Result.WorldPoint = Hit.ImpactPoint;
						UE_LOG(LogTemp, Log, TEXT("Unit selected: %s"), *Character->GetName());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Selected unit is not an ally"));
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Clicked actor is not a character"));
				}
			}
			return;
		// 2- Eligiendo objetivo de la carta
		} else if (SelectionState == ECardSelectionState::SelectingTarget)
		{
			ACharacterBase* TargetUnit = nullptr;
			FVector TargetLocation = FVector::ZeroVector;
			
			// Elegir enemigo
			if (Result.bHitUnit)
			{
				TargetUnit = Cast<ACharacterBase>(Hit.GetActor());
				TargetLocation = Hit.ImpactPoint;
			// Elegir casilla del tablero
			} else if (Result.bHitBoard)
			{
				TargetLocation = Hit.ImpactPoint;
			}
			
			// Comprobar que hay una carta y unidad ya seleccionadas
			if (PendingCard && PendingSource)
			{
				if (BM)
				{
					BM->PlayCard(PendingCard, PendingSource, TargetUnit, TargetLocation);
				}
			}

			// Resetear selección
			PendingCard = nullptr;
			PendingSource = nullptr;
			SelectionState = ECardSelectionState::None;
			CurrentIntent = EInputIntent::Move;

			return;
		}
	}
	
	if (CurrentIntent == EInputIntent::Action)
	{
		if (TraceUnderCursor(UnitChannel, Hit))
		{
			Result.bHit =true;
			Result.bHitUnit = true;
			Result.HitActor = Hit.GetActor();
			Result.WorldPoint = Hit.ImpactPoint;
		}
	}

	else //Movement
	{
		if (TraceUnderCursor(BoardChannel, Hit))
		{
			Result.bHit =true;
			Result.bHitBoard = true;
			Result.HitActor = Hit.GetActor();
			Result.WorldPoint = Hit.ImpactPoint;
		}
	}

	if (Result.bHitBoard && Result.HitActor)
	{
		if (ABoard* Board = Cast<ABoard>(Result.HitActor))
		{
			FTileCoord Tile;
			if (Board->WorldPointToTile(Result.WorldPoint, Tile))
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(
						-1, 2.0f, FColor::Yellow,
						FString::Printf(TEXT("Tile = (%d, %d)"), Tile.X, Tile.Y)
					);
				}

				// Debug visual del centro de la casilla
				const FVector Center = Board->TileToWorldCenter(Tile);
				DrawDebugSphere(GetWorld(), Center, 18.f, 12, FColor::Yellow, false, 2.0f);
			}
			else
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Click fuera del tablero"));
				}
			}
		}
		else
		{
			// Si aquí entras, significa que el actor golpeado NO es tu ABoard.
			// O estás golpeando otro actor distinto, o el mesh que bloquea no pertenece a ABoard.
			UE_LOG(LogTemp, Warning, TEXT("HitActor is not ABoard. Actor=%s"), *Result.HitActor->GetName());
		}
	}

	
	// Debug rápido
	if (GEngine)
	{
		const FString ModeStr = (CurrentIntent == EInputIntent::Action) ? TEXT("Action") : TEXT("Move");
		const FString HitStr =
			(!Result.bHit) ? TEXT("Nothing") :
			(Result.bHitUnit ? TEXT("Unit") : TEXT("Board"));

		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green,
			FString::Printf(TEXT("Mode=%s | Hit=%s | Actor=%s"),
				*ModeStr, *HitStr, Result.HitActor ? *Result.HitActor->GetName() : TEXT("None")));
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Cyan, TEXT("IA_Click triggered"));
	}
	
	if (Result.bHit)
	{
		DrawDebugSphere(GetWorld(), Result.WorldPoint, 10.f, 12, FColor::Green, false, 1.0f);
	}

	BP_OnclickResolved(Result);
}


bool ABoardPlayerController::TraceUnderCursor(ECollisionChannel Channel, FHitResult& OutHit) const
{
	FVector WorldOrigin, WorldDirection;
	if (!DeprojectMousePositionToWorld(WorldOrigin, WorldDirection))
	{
		return false;
	}

	const float TraceDistance = 200000.f;
	const FVector Start = WorldOrigin;
	const FVector End = WorldOrigin + (WorldDirection * TraceDistance);



	FCollisionQueryParams Params(SCENE_QUERY_STAT(ClickTrace), true);
	const bool bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, Params);

	if (bHit)
	{
		DrawDebugSphere(GetWorld(), OutHit.ImpactPoint, 12.f, 12, FColor::Green, false, 2.0f);
	}

	return bHit;
}

// Gestionar controles cuando se abre un menu (ya sea de pausa, tutorial, etc.)
void ABoardPlayerController::OpenMenu()	// De momento solo el de pausa
{
	bIsInMenu = true;
	
	// Desactivar InputMappingContext
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->RemoveMappingContext(IMCGameplay);
		}
	}
	
	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);
}

// Cerrar menus y activar los inputs para el juego
void ABoardPlayerController::CloseMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("CloseMenu"));
	bIsInMenu = false;
	
	// Activar InputMappingContext
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(IMCGameplay, 0);
		}
	}
	
	SetInputMode(FInputModeGameAndUI());
}

// Cambiar estado del Menu
void ABoardPlayerController::HandleMenu()
{
	bIsInMenu ? CloseMenu() : OpenMenu();
}

// Comprobar e iniciar accion de jugar carta
void ABoardPlayerController::BeginPlayCard(UBaseCard* Card)
{
	if (!Card) return;
	
	if (!BM || !BM->IsPlayerTurn())
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot play card: Not player turn"));
		return;
	}
	
	PendingCard = Card;
	PendingSource = nullptr;
	SelectionState = ECardSelectionState::SelectingUnit;

	CurrentIntent = EInputIntent::Action; // Cambiar estado a accion (elegir unidades para jugar la carta)
}