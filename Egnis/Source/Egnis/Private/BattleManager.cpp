#include "BattleManager.h"
#include "DeckManager.h"
#include "BaseCard.h"
#include "CharacterBase.h"
#include "EnergyComponent.h"
#include "EngineUtils.h"

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
		if (Character->GetTeam() == 0)
			Character->GainPoints(-1);
	}
	
	if (DeckManager && DeckManager->GetHand().Num() < DeckManager->GetInitialHandSize())
	{
		DeckManager->DrawCardAmount(DeckManager->GetInitialHandSize());
	}
	
	UE_LOG(LogTemp, Log, TEXT("Player Turn %d"), TurnCount);
}

// Turno del enemigo
void UBattleManager::StartEnemyTurn()
{
	UE_LOG(LogTemp, Log, TEXT("Enemy Turn %d"), TurnCount);
	//TODO: Llamar a la IA del enemigo
	/*//identifica enemigos
	TArray<AEnemy*> Enemies;
	int32 index = 0;
	for (ACharacterBase* Character : CharactersOnField)
	{
		if (Character->GetTeam() == 1)
		{
			Enemies[index];
			index++;
		}
	}

	for (AEnemy* Enemy:Enemies)
	{
		Enemy->MoveTowardClosesPlayer();
		Enemy->MakeAction();
	}*/
	
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

//TODO: Funcion para elegir un aliado haciendo click en el (y habilitar usar cartas)


// Comprobar si el player puede jugar una carta (es decir, que sea su turno y tenga energia)
bool UBattleManager::PlayCard(UBaseCard* Card, ACharacterBase* Character,
	ACharacterBase* TargetCharacter, FVector Location)
{
	// Comprobaciones
	if (CurrentTurn != ETurnEnum::PlayerTurn || !Card || !DeckManager)
	{
		return false;
	}
	
	if (Character->EnergyComp->GetCurrentPoints() < Card->GetCost())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not enough energy to play card"));
		return false;
	} else
	{
		// Jugar carta y restar coste
		Character->LossPoints(Card->GetCost());
		UE_LOG(LogTemp, Log, TEXT("Played card: %s. Energy left: %d"), *Card->GetName(), 
			Character->EnergyComp->GetCurrentPoints());
		Card->Execute(DeckManager, Character, TargetCharacter, Location);
		UpdateUnitsAlive();
	
		return true;
	}
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
	
	//TODO: Notificar al GameMode (no entra en prototipo)
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