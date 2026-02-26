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
#pragma region Functions
	// Acciones de las cartas
	void Execute(UDeckManager* Deck, ACharacterBase* Self, ACharacterBase* TargetCharacter, FVector Location);
	// Getters
	FText GetCardName() const;
	ECardType GetCardType() const;
	EColorType GetColor() const;
	int32 GetCost() const;
	ECardTarget GetTarget() const;
#pragma endregion
	
private:
	
#pragma region Stats
	UPROPERTY()
	FText CardName;
	
	UPROPERTY()
	ECardType CardType;
	
	UPROPERTY()
	EColorType Color;
	
	UPROPERTY()
	int32 Cost;
	
	UPROPERTY()
	ECardTarget Target = ECardTarget::None;
	
	UPROPERTY()
	TArray<UCardEffect*> Effects;

#pragma endregion
};