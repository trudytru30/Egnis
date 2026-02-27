#include "Card_AttackEffect.h"


void UCard_AttackEffect::Execute_Enemy(ACharacterBase* Self, ACharacterBase* Enemy)
{
	Super::Execute_Enemy(Self, Enemy);
	
	// Comprobar que la carta hace danio y que el objetivo es tipo characterBase
	if (DamageAmount >= 0 && Enemy->ACharacterBase::GetTeam() != Self->ACharacterBase::GetTeam())
	{
		Enemy->LossHealth(DamageAmount);
	}
}