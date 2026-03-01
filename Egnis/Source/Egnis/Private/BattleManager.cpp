#include "BattleManager.h"
#include "Ally.h"
#include "DeckManager.h"
#include "BaseCard.h"
#include "CharacterBase.h"
#include "Enemy.h"
#include "EnergyComponent.h"
#include "EngineUtils.h"

class AAlly;
// Iniciar combate
void UBattleManager::Initialize(UDeckManager* InDeckManager)
{
	// Recibir el mazo de combate e inicializarlo, despues empieza el combate
	DeckManager = InDeckManager;	
	if (DeckManager)
		DeckManager->InitializeDeck();
}

// Inicio del combate, se inicializa el mazo, la vida de los personajes y las posiciones
void UBattleManager::StartBattle()
{
	TurnCount = 0;
	CurrentTurn = ETurnEnum::PlayerTurn;
	
	// Obtener numero de personajes en el campo
	CharactersOnField.Empty();
	for (TActorIterator<ACharacterBase> It(GetWorld()); It; ++It)
	{
		CharactersOnField.Add(*It);
	}
	
	UE_LOG(LogTemp, Log, TEXT("Battle Started! Characters on field: %d"), CharactersOnField.Num());
	
	StartPlayerTurn();
}

// Turno del player
void UBattleManager::StartPlayerTurn()
{
	// Robar mano al inicio del turno y establecer energia
	for (ACharacterBase* Character : CharactersOnField)
	{
		if (AAlly* Ally = Cast<AAlly>(Character))
			Ally->GainPoints(-1);	// Para reiniciar los puntos al valor default (mirar EnergyComponent)
	}
	
	if (DeckManager && DeckManager->GetHand().Num() < DeckManager->GetInitialHandSize())
	{
		DeckManager->DrawCardAmount(DeckManager->GetInitialHandSize());
		UE_LOG(LogTemp, Log, TEXT("Drawn %d cards"), DeckManager->GetHand().Num());
	}
	
	UE_LOG(LogTemp, Log, TEXT("Player Turn %d"), TurnCount);
}

// Turno del enemigo
void UBattleManager::StartEnemyTurn()
{
	UE_LOG(LogTemp, Log, TEXT("Enemy Turn %d"), TurnCount);
	//TODO: Llamar a la IA del enemigo
	//identifica enemigos
	TArray<AEnemy*> Enemies;

	for (ACharacterBase* Character : CharactersOnField)
	{
		if (!Character) continue;

		if (Character->GetTeam() == 1)
		{
			if (AEnemy* Enemy = Cast<AEnemy>(Character))
			{
				Enemies.Add(Enemy);
			}
		}
	}

	for (AEnemy* Enemy:Enemies)
	{
		Enemy->MoveTowardClosesPlayer();
		Enemy->MakeAction();
	}
	
	// Comprobar estado de unidades despues de cada turno enemigo y terminar el turno
	UpdateUnitsAlive();
	EndTurn();
}

// Fin del turno y cambio al otro bando
void UBattleManager::EndTurn()
{
	switch ( CurrentTurn)
	{
		case ETurnEnum::PlayerTurn:
			if (DeckManager->GetHand().Num() > 0)
			{
				const TArray<UBaseCard*> HandCopy = DeckManager->GetHand();
				for (UBaseCard* Card : HandCopy)
				{
					DeckManager->DiscardCardFromHand(Card);
				}
			}
		
			CurrentTurn = ETurnEnum::EnemyTurn;
			StartEnemyTurn();
			break;
		case ETurnEnum::EnemyTurn:
			CurrentTurn = ETurnEnum::PlayerTurn;
			TurnCount++;
			StartPlayerTurn();
			break;
	default: UE_LOG(LogTemp, Warning, TEXT("Invalid turn"));
	}
}

// Comprobar si el player puede jugar una carta (es decir, que sea su turno y tenga energia)
bool UBattleManager::PlayCard(UBaseCard* Card, AAlly* Character,
	ACharacterBase* TargetCharacter, FVector Location)
{
	if (!Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("BattleManager: Character is null"));
		return false;
	}
	if (!Character->EnergyComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("BattleManager: EnergyComp is null"));
		return false;
	}
	
	// Comprobaciones
	if (CurrentTurn != ETurnEnum::PlayerTurn || !Card || !DeckManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("BattleManager: Not player turn or card is null"));
		return false;
	}
	
	if (Character->EnergyComp->GetCurrentPoints() < Card->GetCost())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not enough energy to play card"));
		return false;
	}
	
	// Jugar carta y restar coste
	if (!Character || !Character->EnergyComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("BattleManager: Character or EnergyComp is null"));
		return false;
	}
	Character->LossPoints(Card->GetCost());
	UE_LOG(LogTemp, Log, TEXT("Played card: %s. Energy left: %d"), *Card->GetName(), 
		Character->EnergyComp->GetCurrentPoints());
	Card->Execute(DeckManager, Character, TargetCharacter, Location);
	UpdateUnitsAlive();

	return true;
}

// Gestionar las unidades que hay en el campo de batalla (despues de cada carta/ accion enemiga lo suyo es llamar a esto)
void UBattleManager::UpdateUnitsAlive()
{
	int32 AlliesAlive = 0;
	int32 EnemiesAlive = 0;
	
	// Limpiar punteros invalidos
	for (int32 i = CharactersOnField.Num()-1; i >= 0; i--)
	{
		if (!IsValid((CharactersOnField[i])))
			CharactersOnField.RemoveAt(i);
	}
	
	// Comrpobar cuantos aliados y enemigos quedan en campo
	for (ACharacterBase* Character : CharactersOnField)
	{
		if (Character->GetTeam() == 0)
		{
			AlliesAlive++;
		}
		else
		{
			EnemiesAlive++;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Allies alive: %d, Enemies alive: %d"), AlliesAlive, EnemiesAlive);
	
	if (AlliesAlive == 0)
		EndBattle(false);
	else if (EnemiesAlive == 0)
		EndBattle(true);
}

// Fin del combate
void UBattleManager::EndBattle(bool bPlayerWon)
{
	if (bPlayerWon)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
			TEXT("PLAYER WINS"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
			TEXT("PLAYER LOST"));
	}
	
	//TODO: Notificar al GameMode (no entra en prototipo)
}

// Pedir movimiento
bool UBattleManager::RequestMove(ACharacterBase* Unit, const FTileCoord& TargetTile)
{
	if (!Unit)
	{
		UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: Unit is null"));
		return false;
	}
	if (!IsPlayerTurn())
	{
		UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: Not player turn"));
		return false;
	}
	if (Unit->GetTeam() != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: Unit is not ally"));
		return false;
	}
	if (!Unit->Board)
	{
		UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: Unit has no Board"));
		return false;
	}

	const FTileCoord Start = Unit->CurrentTile;

	const int32 DeltaX = TargetTile.X - Start.X;
	const int32 DeltaY = TargetTile.Y - Start.Y;

	const int32 AbsX = FMath::Abs(DeltaX);
	const int32 AbsY = FMath::Abs(DeltaY);
	const int32 Dist = AbsX + AbsY;

	if (Dist == 0)
	{
		return true;
	}
	if (Dist > 2)
	{
		UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: too far (dist=%d). Max=2"), Dist);
		return false;
	}

	// Helpers: signo de avance en cada eje
	const int32 StepX = (DeltaX == 0) ? 0 : (DeltaX > 0 ? 1 : -1);
	const int32 StepY = (DeltaY == 0) ? 0 : (DeltaY > 0 ? 1 : -1);

	// ---- Caso 1: movimiento recto (2,0) o (0,2) o (1,0) o (0,1) ----
	if (AbsX == 0 || AbsY == 0)
	{
		// Primer paso
		FTileCoord Step1(Start.X + StepX, Start.Y + StepY);

		if (!Unit->SetCurrentTile(Step1))
		{
			UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: step1 blocked (%d,%d)"), Step1.X, Step1.Y);
			return false;
		}

		// Segundo paso si Dist==2
		if (Dist == 2)
		{
			FTileCoord Step2(Step1.X + StepX, Step1.Y + StepY);

			if (!Unit->SetCurrentTile(Step2))
			{
				UE_LOG(LogTemp, Warning, TEXT("RequestMove partial: step2 blocked (%d,%d). Staying at step1."), Step2.X, Step2.Y);
				Unit->SnapToCurrentTile(false);
				return true;
			}
		}

		Unit->SnapToCurrentTile(false);
		UE_LOG(LogTemp, Log, TEXT("RequestMove OK: %s -> (%d,%d)"),
			*Unit->GetName(), Unit->CurrentTile.X, Unit->CurrentTile.Y);
		return true;
	}

	// ---- Caso 2: diagonal tipo "L" (1,1) ----
	// Dist==2 y AbsX==1 y AbsY==1
	if (Dist == 2 && AbsX == 1 && AbsY == 1)
	{
		// Ruta A: X luego Y
		const FTileCoord AX1(Start.X + StepX, Start.Y);
		const FTileCoord AX2(Start.X + StepX, Start.Y + StepY); // destino

		// Ruta B: Y luego X
		const FTileCoord BY1(Start.X, Start.Y + StepY);
		const FTileCoord BY2(Start.X + StepX, Start.Y + StepY); // destino

		// Intento A
		{
			// Guardamos tile actual por si queremos revertir (SetCurrentTile ya gestiona ocupación)
			const FTileCoord Orig = Unit->CurrentTile;

			if (Unit->SetCurrentTile(AX1))
			{
				if (Unit->SetCurrentTile(AX2))
				{
					Unit->SnapToCurrentTile(false);
					UE_LOG(LogTemp, Log, TEXT("RequestMove OK (X->Y): %s -> (%d,%d)"),
						*Unit->GetName(), Unit->CurrentTile.X, Unit->CurrentTile.Y);
					return true;
				}

				// No pudo hacer segundo paso: se queda en AX1
				Unit->SnapToCurrentTile(false);
				UE_LOG(LogTemp, Warning, TEXT("RequestMove partial (X->Y): second step blocked, staying at (%d,%d)"),
					Unit->CurrentTile.X, Unit->CurrentTile.Y);
				return true;
			}

			// Si falla el primer paso A, probamos B desde Orig (sin cambios)
			// (Si SetCurrentTile falló, Unit sigue en Orig)
		}

		// Intento B
		if (Unit->SetCurrentTile(BY1))
		{
			if (Unit->SetCurrentTile(BY2))
			{
				Unit->SnapToCurrentTile(false);
				UE_LOG(LogTemp, Log, TEXT("RequestMove OK (Y->X): %s -> (%d,%d)"),
					*Unit->GetName(), Unit->CurrentTile.X, Unit->CurrentTile.Y);
				return true;
			}

			// No pudo hacer segundo paso: se queda en BY1
			Unit->SnapToCurrentTile(false);
			UE_LOG(LogTemp, Warning, TEXT("RequestMove partial (Y->X): second step blocked, staying at (%d,%d)"),
				Unit->CurrentTile.X, Unit->CurrentTile.Y);
			return true;
		}

		UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: both diagonal paths blocked."));
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("RequestMove failed: unsupported move pattern."));
	return false;
}

// ===== Getters =====
int32 UBattleManager::GetTurnCount() const
{
	return TurnCount;
}

TArray<ACharacterBase*> UBattleManager::GetCharactersOnField() const
{
	return CharactersOnField;
}

bool UBattleManager::IsPlayerTurn() const
{
	return CurrentTurn == ETurnEnum::PlayerTurn;
}