#include "Card_HealEffect.h"

void UCard_HealEffect::Execute(ACharacterBase* Source, ACharacterBase* Target)
{
	// Comprobar que la carta hace curacion y que el el objetivo al que curar es
	// del mismo equipo que el que lanza la carta
	if (HealAmount >= 0 && Source-> GetTeam() == Target->GetTeam())
	{
		Target->GainHealth(HealAmount);
	}
}