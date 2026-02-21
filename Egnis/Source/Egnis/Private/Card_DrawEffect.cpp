#include "Card_DrawEffect.h"
#include "DeckManager.h"

void UCard_DrawEffect::Execute(UDeckManager* Deck)
{
	if (!Deck) return;
	
	Deck->DrawCard();	//TODO: Para versión final, cambiar DrawCard para que reciba cuantas cartas se roban
}