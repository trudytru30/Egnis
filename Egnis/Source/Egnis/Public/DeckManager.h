#pragma once

#include "CoreMinimal.h"

class UBaseCard;

class EGNIS_API UDeckManager : UObject
{
	// TODO: En un futuro hacer publica la mano (el turnManager necesita saber el coste de las cartas)
	
protected:
	TArray<UBaseCard> Deck;
	TArray<UBaseCard> DrawPile;
	TArray<UBaseCard> DiscardedPile;
	TArray<UBaseCard> Hand;
	
	// ===== Funciones =====
	void InitializeDeck();
	void ShuffleDeck();
	void DrawCard();
	void DiscardCard();
	void AddCardToDeck(TSubclassOf<class UBaseCard> Card);
	void RemoveCardFromDeck(TSubclassOf<class UBaseCard> Card);
	void ResetDeck();	// Limpiar el mazo despues de cada batalla (Draw, Discarded y hand)
private:
	int32 InitialDeckSize = 20;
	int32 CurrentDeckSize = InitialDeckSize;
	int32 InitialHandSize = 6;
	int32 MaxHandSize = 9;
};
