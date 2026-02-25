#include "DeckManager.h"

// Aniadir cartas al mazo
void UDeckManager::GenerateDeck(const TArray<TSubclassOf<UBaseCard>>& SelectedCarts)
{
	if (SelectedCarts.Num() < InitialDeckSize)
	{
		UE_LOG(LogTemp, Error, TEXT("No hay suficientes cartas seleccionadas para generar el mazo"));
		return;
	}
	
	Deck.Empty();	// Limpiar mazo antes de añadir las nuevas
	
	for (TSubclassOf<UBaseCard> Card : SelectedCarts)
	{
		if (!Card) continue;	// Comprobar que no es null
		Deck.Add(NewObject<UBaseCard>(this, Card));
	}
}

// Inicializar mazo al principio de la batalla
void UDeckManager::InitializeDeck()
{
	DrawPile = Deck;
	DiscardedPile.Empty();
	Hand.Empty();
	
	ShuffleDeck();
	
	// Robar mano inicial
	for (int32 i = 0; i < InitialHandSize; i++)
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

// Robar cartas mediante habilidades
void UDeckManager::DrawCard()
{
	//TODO: El TurnManager es el que tiene que comprobar esto junto a que haya cartas en la pila de robo
	if (Hand.Num() >= MaxHandSize) return;	
	
	if (DrawPile.Num() <= 0)
	{
		DrawPile = DiscardedPile;
		DiscardedPile.Empty();
		ShuffleDeck();
	} else if (DrawPile.Num() > 0)
	{
		Hand.Add(DrawPile.Last());
		DrawPile.Pop();
	}
}

// Robar cartas (con habilidades)
void UDeckManager::DrawCardAmount(int32 Amount)
{
	for (int32 i = 0; i < Amount; i++)
	{
		DrawCard();
	}
}

// Descartar mano completa
void UDeckManager::DiscardHand()
{
	for (UBaseCard* Card : Hand)
	{
		DiscardCardFromHand(Card);
		DiscardedPile.Add(Card);
	}
}

// Descartar cartas de la mano a la pila de descarte
void UDeckManager::DiscardCardFromHand(UBaseCard* Card)
{
	if (Hand.Contains(Card))
	{
		Hand.Remove(Card);
		DiscardedPile.Add(Card);
	}
}

// Descartar cartas del mazo a la pila de descarte
void UDeckManager::DiscardCardFromDrawPile(UBaseCard* Card)
{
	if (DrawPile.Contains(Card))
	{
		DrawPile.Remove(Card);
		DiscardedPile.Add(Card);
	}
}

// Aniadir cartas al mazo permanentemente
void UDeckManager::AddCardToDeck(UBaseCard* Card)
{
	Deck.Add(Card);
}

// Eliminar una carta del mazo permanentemente
void UDeckManager::RemoveCardFromDeck(UBaseCard* Card)
{
	Deck.RemoveSingle(Card);
}

// Reiniciar mazo (al terminar una partida, no una batalla)
void UDeckManager::ResetDeck()
{
	Deck.Empty();
	DrawPile.Empty();
	DiscardedPile.Empty();
	Hand.Empty();
}