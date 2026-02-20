#pragma once

#include "CoreMinimal.h"
#include "CardEffect.generated.h"

UCLASS(Blueprintable, Abstract)
class EGNIS_API UCardEffect : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void Execute() PURE_VIRTUAL(class AActor* Source = nullptr, class AActor* Target = nullptr;);
};