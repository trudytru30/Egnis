#include "GameManager.h"
#include "BoardPlayerController.h"
#include "BattleManager.h"
#include "DeckManager.h"

AGameManager::AGameManager()
{
	PlayerControllerClass = ABoardPlayerController::StaticClass();
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeManagers();
}

void AGameManager::InitializeManagers()
{
	// Crear PlayerController
	DeckManager = NewObject<UDeckManager>(this);
	check(DeckManager);
	DeckManager->SetDeck(InitialDeck);
	
	// Crear BattleManager
	BattleManager = NewObject<UBattleManager>(this);
	check(BattleManager);
	BattleManager->Initialize(DeckManager);
	
	// Iniciar combate
	BattleManager->StartBattle();
}