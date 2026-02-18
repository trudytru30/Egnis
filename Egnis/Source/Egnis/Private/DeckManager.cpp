#include "DeckManager.h"

// Inicializar mazo al principio de la batalla
void UDeckManager::InitializeDeck()
{
	DrawPile = Deck;
	
	ShuffleDeck();
	
	// Robar mano inicial
	for (int32 i = 0; i < CurrentDeckSize; i++)
	{
		DrawCard();
	}
}

// Barajar cartas de forma aleatoria
void UDeckManager::ShuffleDeck()
{
	for (int32 i = 0; i < DrawPile.Num(); i++)
	{
		int32 RandomIndex = FMath::RandRange(0, DrawPile.Num() - 1);
		DrawPile.Swap(i, RandomIndex);
	}
}

// Robar cartas del mazo
void UDeckManager::DrawCard()
{
	if (DrawPile.Num() > 0)
	{
		Hand.Add(DrawPile.Last());
		DrawPile.Pop();
	}
	
	if (DrawPile.Num() <= 0)
	{
		DrawPile = DiscardedPile;
		DiscardedPile.Empty();
		ShuffleDeck();
	}
}

// Descartar cartas a la pila de descarte
void UDeckManager::DiscardCard()
{
	
}

// Aniadir cartas al mazo permanentemente
void UDeckManager::AddCardToDeck(TSubclassOf<class UBaseCard> Card)
{
	
}

// Eliminar una carta del mazo permanentemente
void UDeckManager::RemoveCardFromDeck(TSubclassOf<class UBaseCard> Card)
{
	
}

// Reiniciar mazo (al terminar una partida, no una batalla)
void UDeckManager::ResetDeck()
{
	Deck.Empty();
	DrawPile.Empty();
	DiscardedPile.Empty();
	Hand.Empty();
}