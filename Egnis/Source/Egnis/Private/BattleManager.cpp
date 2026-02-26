#include "BattleManager.h"
#include "DeckManager.h"
#include "BaseCard.h"
#include "CharacterBase.h"
#include "EngineUtils.h"

// Inicializar combate
void UBattleManager::Initialize(UDeckManager* InDeckManager)
{
	DeckManager = InDeckManager;
}

// Inicio del combate, se inicializa el mazo, la vida de los personajes y las posiciones
void UBattleManager::StartBattle()
{
	TurnCount = 0;
	CurrentTurn = ETurnEnum::PlayerTurn;
	
	// Obtener numero de personajes en el campo
	CharactersOnField.Empty();
	for (TActorIterator<ACharacterBase> It(GetWorld()); It; ++It)
		CharactersOnField.Add(*It);
	
	UE_LOG(LogTemp, Log, TEXT("Battle Started! Characters on field: %d"), CharactersOnField.Num());
	
	StartPlayerTurn();
}

// Turno del player
void UBattleManager::StartPlayerTurn()
{
	// Robar mano al inicio del turno y establecer energia
	CurrentEnergy = InitialEnergy;
	
	if (DeckManager)
	{
		DeckManager->DrawCardAmount(DeckManager->GetInitialHandSize());	
	}
	
	UE_LOG(LogTemp, Log, TEXT("Player Turn %d, energy: %d"), TurnCount, CurrentEnergy);
}

// Turno del enemigo
void UBattleManager::StartEnemyTurn()
{
	UE_LOG(LogTemp, Log, TEXT("Enemy Turn %d"), TurnCount);
	//TODO: Llamar a la IA del enemigo
	
	// Comprobar estado de unidades despues de cada turno enemigo
	UpdateUnitsAlive();
}

// Fin del turno y cambio al otro bando
void UBattleManager::EndTurn()
{
	if (CurrentTurn == ETurnEnum::PlayerTurn)
	{
		CurrentTurn = ETurnEnum::EnemyTurn;
		StartEnemyTurn();
	} else
	{
		CurrentTurn = ETurnEnum::PlayerTurn;
		TurnCount++;
		StartPlayerTurn();
	}
}

bool UBattleManager::PlayCard(UBaseCard* Card, ACharacterBase* Character, ACharacterBase* TargetCharacter, FVector Location)
{
	// Comprobaciones
	if (CurrentTurn != ETurnEnum::PlayerTurn || !Card || !DeckManager)
	{
		return false;
	}
	
	if (CurrentEnergy < Card->GetCost())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not enough energy to play card"));
		return false;
	}
	
	// Jugar carta y restar coste
	CurrentEnergy -= Card->GetCost();
	UE_LOG(LogTemp, Log, TEXT("Played card: %s. Energy left: %d"), *Card->GetName(), CurrentEnergy);
	Card->Execute(DeckManager, Character, TargetCharacter, Location);
	UpdateUnitsAlive();
	
	return true;
}

// Gestionar las unidades que hay en el campo de batalla (despues de cada carta/ accion enemiga lo suyo es llamar a esto)
void UBattleManager::UpdateUnitsAlive()
{
	int32 AlliesAlive = 0;
	int32 EnemiesAlive = 0;
	
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
	
	//TODO: Notificar al GameMode
}

// ===== Getters =====
int32 UBattleManager::GetTurnCount() const
{
	return TurnCount;
}

int32 UBattleManager::GetCurrentEnergy() const
{
	return CurrentEnergy;
}