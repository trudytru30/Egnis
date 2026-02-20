#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CharacterBase.h"
#include "Card_HealEffect.generated.h"

UCLASS()
class EGNIS_API UCard_HealEffect : public UCardEffect
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealEffect")
	int32 HealAmount;
	
	virtual void Execute(ACharacterBase* Source = nullptr, ACharacterBase* Target = nullptr);
};