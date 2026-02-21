#pragma once

#include "CoreMinimal.h"
#include "CardEffect.generated.h"

class UDeckManager;

UCLASS(Blueprintable, Abstract)
class EGNIS_API UCardEffect : public UObject
{
	GENERATED_BODY()
	
public:
	//TODO: Cambiar logica de execute
	virtual void Execute() PURE_VIRTUAL(class AActor* Source = nullptr, class AActor* Target = nullptr;)
	void Execute(UDeckManager* Deck);;
};