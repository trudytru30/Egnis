#include "Card_HealEffect.h"

void UCard_HealEffect::Execute_Ally(ACharacterBase* Self, ACharacterBase* Ally)
{
	Super::Execute_Ally(Self, Ally);
	
	// Comprobar que la carta hace curacion y que el el objetivo al que curar es
	// del mismo equipo que el que lanza la carta
	if (HealAmount >= 0 && Self->GetTeam() == Ally->GetTeam())
	{
		Ally->GainHealth(HealAmount);
	}
}