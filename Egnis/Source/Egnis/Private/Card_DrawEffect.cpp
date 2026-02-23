#include "Card_DrawEffect.h"
#include "DeckManager.h"

void UCard_DrawEffect::Execute_None(UDeckManager* Deck)
{
	Super::Execute_None(Deck);
	
	if (!Deck) return;
	
	Deck->DrawCardAmount(DrawAmount);
}