#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "Card_DrawEffect.generated.h"

class UDeckManager;

UCLASS(EditInlineNew)
class EGNIS_API UCard_DrawEffect : public UCardEffect
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Draw")
	int32 DrawAmount = 1;
	
	virtual void Execute_None(UDeckManager* Deck) override;
};