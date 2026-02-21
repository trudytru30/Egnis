#include "BaseCard.h"

// Utilizar carta
void UBaseCard::Execute(UDeckManager* Deck)
{
	for (UCardEffect* Effect : Effects)
	{
		if (Effect)
		{
			Effect->Execute(Deck);
		}
	}
}