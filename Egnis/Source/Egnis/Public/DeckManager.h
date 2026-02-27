#pragma once

#include "CoreMinimal.h"
#include "BaseCard.h"
#include "DeckManager.generated.h"

class UBaseCard;

UCLASS()
class EGNIS_API UDeckManager : public UObject
{
	GENERATED_BODY()
	
public:

#pragma region Functions
	// Modificar las cartas del mazo elegidas por el player
	void GenerateDeck(const TArray<TSubclassOf<UBaseCard>>& SelectedCarts);
	void InitializeDeck();	// Generar mazo para la batalla
	void ResetDeck();	// Limpiar los mazo despues de cada batalla (Draw, Discarded y hand)
	void DrawCard();
	void DrawCardAmount(int32 Amount);
	void ShuffleDeck();
	void DiscardCardFromHand(UBaseCard* Card);
	void DiscardCardFromDrawPile(UBaseCard* Card);
	void AddCardToDeck(UBaseCard* Card);
	void RemoveCardFromDeck(UBaseCard* Card);
	// Getters
	int32 GetInitialHandSize();
	int32 GetMaxHandSize();
	TArray<UBaseCard*> GetHand();
#pragma endregion
	
private:
	
#pragma region Properties
	UPROPERTY()
	TArray<UBaseCard*> TotalCards;
	
	UPROPERTY()
	TArray<TSubclassOf<UBaseCard>> SelectedCards;
	
	UPROPERTY()
	TArray<UBaseCard*> Deck;
	
	UPROPERTY()
	TArray<UBaseCard*> DrawPile;
	
	UPROPERTY()
	TArray<UBaseCard*> DiscardedPile;
	
	UPROPERTY()
	TArray<UBaseCard*> Hand;
	
	int32 InitialDeckSize = 20;
	int32 InitialHandSize = 6;
	int32 MaxHandSize = 9;
#pragma endregion
};