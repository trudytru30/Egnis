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
	
public:
	
	// ===== PROPIEDADES =====
#pragma region Properties
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
#pragma endregion
	
	// ===== FUNCIONES =====
	void DrawCard();	// TODO: Llamar desde TurnManager
	void DrawCardAmount(int32 Amount);
	void ShuffleDeck();
	void DiscardCardFromHand(UBaseCard* Card);	// TODO: Llamar desde TurnManager (al terminar el turno del jugador)
	void DiscardCardFromDrawPile(UBaseCard* Card);
	void AddCardToDeck(UBaseCard* Card);
	void RemoveCardFromDeck(UBaseCard* Card);

private:
	
#pragma region DeckStats
	int32 InitialDeckSize = 20;
	int32 InitialHandSize = 6;
	int32 MaxHandSize = 9;
#pragma endregion
	
#pragma region Functions
	// ===== Funciones =====
	
	// Llamar al modificar las cartas del mazo elegidas por el player
	void GenerateDeck(const TArray<TSubclassOf<UBaseCard>>& SelectedCarts);
	// Llamar al actualizar el mazo con cartas temporales (invocaciones, etc.)
	// UpdateCombatDeck(UBaseCard* TempCard);
	// Llamar al inicio de cada combate, genera el mazo y roba la primera mano
	void InitializeDeck();	
	// Limpiar el mazo despues de cada batalla (Draw, Discarded y hand)
	void ResetDeck();
#pragma endregion
};