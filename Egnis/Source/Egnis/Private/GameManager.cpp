#include "GameManager.h"

void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeManagers();
}

void AGameManager::InitializeManagers()
{
	// Crear PlayerController
	PlayerController = NewObject<ABoardPlayerController>(this);
	
	// Crear BattleController
	BattleManager = NewObject<UBattleManager>(this);
	
	// Iniciar combate
	BattleManager->StartBattle();
}