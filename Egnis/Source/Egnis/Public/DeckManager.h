#pragma once

#include "CoreMinimal.h"
#include "BaseCard.h"
#include "DeckManager.generated.h"

class UBaseCard;

UCLASS()
class EGNIS_API UDeckManager : public UObject
{
	// TODO: En un futuro hacer publica la mano (el turnManager necesita saber el coste de las cartas)
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Decks")
	TArray<UBaseCard*> TotalCards;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Decks")
	TArray<TSubclassOf<UBaseCard>> SelectedCards;	// Cartas seleccionadas para aniadir al mazo
	
	UPROPERTY()
	TArray<UBaseCard*> Deck;
	
	UPROPERTY()
	TArray<UBaseCard*> DrawPile;
	
	UPROPERTY()
	TArray<UBaseCard*> DiscardedPile;
	
	UPROPERTY()
	TArray<UBaseCard*> Hand;

private:
	
#pragma region DeckStats
	int32 InitialDeckSize = 20;
	int32 InitialHandSize = 6;
	int32 MaxHandSize = 9;
#pragma endregion
	
#pragma region Functions
	// ===== Funciones =====
	// TODO: Aniadir las cartas elegidas al mazo (esto lo gestiona mejor el GameManager y UI)
	//void SelectCardsToAdd();
	// Llamar al modificar las cartas del mazo elegidas por el player
	void GenerateDeck(const TArray<TSubclassOf<UBaseCard>>& SelectedCarts);
	// Llamar al actualizar el mazo con cartas temporales (invocaciones, etc.)
	// UpdateCombatDeck(UBaseCard* TempCard);
	// Llamar al inicio de cada combate, genera el mazo y roba la primera mano
	void InitializeDeck();	
	void ShuffleDeck();
	void DrawCard();	// TODO: Llamar desde TurnManager
	void DiscardCardFromHand(UBaseCard* Card);	// TODO: Llamar desde TurnManager (al terminar el turno del jugador)
	void DiscardCardFromDrawPile(UBaseCard* Card);
	void AddCardToDeck(UBaseCard* Card);
	void RemoveCardFromDeck(UBaseCard* Card);
	// Limpiar el mazo despues de cada batalla (Draw, Discarded y hand)
	void ResetDeck();
#pragma endregion
};