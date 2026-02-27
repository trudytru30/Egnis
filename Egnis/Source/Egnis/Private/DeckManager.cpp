#include "DeckManager.h"

// Aniadir cartas al mazo
void UDeckManager::GenerateDeck(const TArray<TSubclassOf<UBaseCard>>& SelectedCarts)
{
	if (SelectedCarts.Num() < InitialDeckSize)
	{
		UE_LOG(LogTemp, Error, TEXT("No hay suficientes cartas seleccionadas para generar el mazo"));
		return;
	}
	
	// Limpiar mazo y aniadir las cartas
	ResetDeck();
	for (TSubclassOf Card : SelectedCarts)
	{
		if (!Card) continue;
		AddCardToDeck(NewObject<UBaseCard>(this, Card));
	}
}

// Inicializar mazo al principio de la batalla
void UDeckManager::InitializeDeck()
{
	DrawPile = Deck;
	DiscardedPile.Empty();
	Hand.Empty();
	
	ShuffleDeck();
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

// ===== Getters =====
int32 UDeckManager::GetInitialHandSize()
{
	return InitialHandSize;
}

int32 UDeckManager::GetMaxHandSize()
{
	return MaxHandSize;
}

TArray<UBaseCard*> UDeckManager::GetHand()
{
	return Hand;
}