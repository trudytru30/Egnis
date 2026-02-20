#include "Card_AttackEffect.h"

void UCard_AttackEffect::Execute(AActor* Source, ACharacterBase* Target)
{
	// Comprobar que la carta hace danio y que el objetivo es tipo characterBase
	if (DamageAmount >= 0 && Target->IsA(ACharacterBase::StaticClass()))
	{
		Target->LossHealth(DamageAmount);
	}
}
