#include "BattleManager.h"

#include "HeadMountedDisplayTypes.h"

// Inicio del combate, se inicializa el mazo, la vida de los personajes y las posiciones
void UBattleManager::StartBattle()
{
	UpdateUnitsAlive();	// Contar personajes en el campo de batalla
	
	// Asegurarse de que se crea un mazo distinto
	DeckManager->ResetDeck();	
	DeckManager->InitializeDeck();
}

// Cambio de turno entre player y enemigos
void UBattleManager::TurnChange()
{
	// Alternar turnos
	UpdateUnitsAlive();
	
	CurrentTurn = (CurrentTurn == ETurnEnum::PlayerTurn) ? ETurnEnum::EnemyTurn : ETurnEnum::PlayerTurn;
	TurnNumber++;
	
	if (CurrentTurn == ETurnEnum::PlayerTurn)
		StartPlayerTurn();
	if (CurrentTurn == ETurnEnum::EnemyTurn)
		StartEnemyTurn();
}

// Gestionar las unidades que hay en el campo de batalla 
// (despues de cada carta/ accion enemiga lo suyo es llamar a esto)
void UBattleManager::UpdateUnitsAlive()
{
	// Comprobar que unidades hay en el campo de batalla
	CharactersOnField = 0;
	
	for (ACharacterBase* Unit : AlliesAlive)
		CharactersOnField++;
	
	for (ACharacterBase* Unit : AlliesAlive)
		CharactersOnField++;
	
	
	// Comprobar si ha terminado el combate
	if (AlliesAlive.IsEmpty())
		EndBattle(0);
	else if (EnemiesAlive.IsEmpty())
		EndBattle(1);
}

// Gestionar turno del player
void UBattleManager::StartPlayerTurn()
{
	// Robar mano al inicio del turno
	DeckManager->DrawCard();
	
	
	
	if (bEndTurn)
	{
		DeckManager->DiscardHand();	// Descartar mano al finalizar el turno
		TurnChange();
	}
}

// Gestionar turno del enemigo
void UBattleManager::StartEnemyTurn()
{
	if (bEndTurn)
		TurnChange();
}

// Finalizar la batalla
void UBattleManager::EndBattle(int Team)
{
	switch(Team)
	{
	case 0:
		UE_LOG(LogTemp, Warning, TEXT("Player Won!"));
		break;
	case 1:
		UE_LOG(LogTemp, Warning, TEXT("Player Lose!"));
		break;
	default: UE_LOG(LogTemp, Warning, TEXT("Tie!"));
	}
}