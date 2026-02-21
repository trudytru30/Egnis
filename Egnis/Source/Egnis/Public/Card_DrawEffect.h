#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "Card_DrawEffect.generated.h"

class UDeckManager;

UCLASS()
class EGNIS_API UCard_DrawEffect : public UCardEffect
{
	GENERATED_BODY()
	
	virtual void Execute(UDeckManager* Deck);
};