#pragma once

#include "CoreMinimal.h"
#include "CardTarget.h"
#include "CharacterBase.h"
#include "CardEffect.generated.h"

class UDeckManager;

UCLASS(Blueprintable, Abstract)
class EGNIS_API UCardEffect : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effect")
	ECardTarget Target = ECardTarget::None;
	
	// ===== FUNCIONES =====
	virtual void Execute_None(UDeckManager* Deck) {};
	virtual void Execute_Ally(ACharacterBase* Self, ACharacterBase* Ally) {};
	virtual void Execute_Enemy(ACharacterBase* Self, ACharacterBase* Enemy) {};
	virtual void Execute_Self(ACharacterBase* Source) {};
	virtual void Execute_Tile(FVector Location) {};
};