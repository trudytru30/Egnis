#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CharacterBase.h"
#include "Card_AttackEffect.generated.h"

UCLASS(EditInlineNew)
class EGNIS_API UCard_AttackEffect : public UCardEffect
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AttackEffect")
	int32 DamageAmount;
	
	virtual void Execute_Enemy(ACharacterBase* Self, ACharacterBase* Enemy) override;
};