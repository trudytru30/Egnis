#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CharacterBase.h"
#include "Card_HealEffect.generated.h"

UCLASS(EditInlineNew)
class EGNIS_API UCard_HealEffect : public UCardEffect
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealEffect")
	float HealAmount = 10.0f;
	
	virtual void Execute_Ally(ACharacterBase* Self, ACharacterBase* Ally) override;
};