#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CardTarget.h"
#include "CardType.h"
#include "ColorType.h"
#include "BaseCard.generated.h"

class UDeckManager;
class ACharacterBase;

UCLASS(BlueprintType, Blueprintable)
class EGNIS_API UBaseCard : public UPrimaryDataAsset
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
	
protected:
	
#pragma region Stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card")
	FText CardName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card")
	ECardType CardType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card")
	EColorType Color;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card")
	int32 Cost;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card")
	ECardTarget Target = ECardTarget::None;
	
	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, Category="Card")
	TArray<UCardEffect*> Effects;

#pragma endregion
};