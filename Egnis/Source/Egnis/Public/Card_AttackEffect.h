#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CharacterBase.h"
#include "Card_AttackEffect.generated.h"

UCLASS()
class EGNIS_API UCard_AttackEffect : public UCardEffect
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AttackEffect")
	int32 DamageAmount;
	
	virtual void Execute(AActor* Source = nullptr, ACharacterBase* Target = nullptr);
};