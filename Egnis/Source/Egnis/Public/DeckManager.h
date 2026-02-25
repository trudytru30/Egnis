#pragma once

#include "CoreMinimal.h"
#include "BaseCard.h"
#include "DeckManager.generated.h"

class UBaseCard;

UCLASS()
class EGNIS_API UDeckManager : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY()
	TArray<UBaseCard*> Hand;
	
public:
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
	
	
#pragma endregion

#pragma region Functions
	// Se llama al modificar las cartas del mazo elegidas por el player
	void GenerateDeck(const TArray<TSubclassOf<UBaseCard>>& SelectedCarts);
	
	// Se llama al inicio de cada combate, genera el mazo y roba la primera mano
	void InitializeDeck();
	
	// Barajar mazo (al principio de la batalla y al acabarse el mazo de robo)
	void ShuffleDeck();
	
	// Limpiar el mazo despues de cada batalla (Draw, Discarded y hand)
	void ResetDeck();
	
	// Descartar mano completa (al finalizar el turno)
	void DiscardHand();
	
	// Descartar una carta concreta de la mano (mediante habilidades)
	void DiscardCardFromHand(UBaseCard* Card);
	
	// Descartar cartas del mazo (mediante habilidades o al cambiar de turno)
	void DiscardCardFromDrawPile(UBaseCard* Card);
	
	// Aniadir una carta al mazo (permanente)
	void AddCardToDeck(UBaseCard* Card);
	
	// Descartar una carta del mazo (permanente)
	void RemoveCardFromDeck(UBaseCard* Card);
	
	// Robar una carta
	void DrawCard();
	
	// Robar x numero de cartas
	void DrawCardAmount(int32 Amount);
#pragma endregion

private:
	
#pragma region Deck variables
	int32 InitialDeckSize = 20;
	int32 InitialHandSize = 6;
	int32 MaxHandSize = 9;
#pragma endregion
};