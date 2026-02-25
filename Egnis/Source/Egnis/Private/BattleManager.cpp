#include "BattleManager.h"

// Inicio del combate, se inicializa el mazo, la vida de los personajes y las posiciones
void UBattleManager::StartBattle()
{
	
}

// Cambio de turno entre player y enemigos
void UBattleManager::TurnChange()
{
	// Alternar turnos
	CurrentTurn = (CurrentTurn == ETurnEnum::PlayerTurn) ? ETurnEnum::EnemyTurn : ETurnEnum::PlayerTurn;
	TurnNumber++;
	
	
}

// Gestionar las unidades que hay en el campo de batalla (despues de cada carta/ accion enemiga lo suyo es llamar a esto)
void UBattleManager::UpdateUnitsAlive()
{
	
}