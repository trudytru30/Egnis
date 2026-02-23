#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CardTarget.h"
#include "CardType.h"
#include "ColorType.h"
#include "BaseCard.generated.h"

class UDeckManager;
class ACharacterBase;

UCLASS(BlueprintType, Abstract)
class EGNIS_API UBaseCard : public UObject
{
	GENERATED_BODY()

public:
	
	// ===== Stats =====
#pragma region Stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	FText CardName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	ECardType CardType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	EColorType Color;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	int32 Cost;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	ECardTarget Target = ECardTarget::None;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	TArray<UCardEffect*> Effects;

#pragma endregion
	
	// ===== Funciones =====
	void Execute(UDeckManager* Deck, ACharacterBase* Self, ACharacterBase* TargetCharacter, FVector Location);
};