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
	DeckManager = NewObject<UDeckManager>(this);
	check(DeckManager);
    
	UE_LOG(LogTemp, Warning, TEXT("InitialDeck size: %d"), InitialDeck.Num());
	for (UBaseCard* Card : InitialDeck)
	{
		UE_LOG(LogTemp, Warning, TEXT("Card: %s"), Card ? *Card->GetName() : TEXT("NULL"));
	}
    
	DeckManager->SetDeck(InitialDeck);
	DeckManager->InitializeDeck();
    
	UE_LOG(LogTemp, Warning, TEXT("DrawPile after init: %d"), DeckManager->GetDrawPileSize());
    
	BattleManager = NewObject<UBattleManager>(this);
	check(BattleManager);
	BattleManager->Initialize(DeckManager);
	BattleManager->StartBattle();
    
	UE_LOG(LogTemp, Warning, TEXT("Hand after StartBattle: %d"), DeckManager->GetHand().Num());
}