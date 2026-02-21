#pragma once

#include "CoreMinimal.h"
#include "CardEffect.h"
#include "CardTarget.h"
#include "CardType.h"
#include "ColorType.h"
#include "DeckManager.h"
#include "BaseCard.generated.h"

UCLASS(BlueprintType, Abstract)
class EGNIS_API UBaseCard : public UObject
{
	GENERATED_BODY()

public:
	// ===== Funciones =====
	void Execute(UDeckManager* Deck);	//TODO: Ejecucion de cartas sin terminar
	
protected:
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
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	UTexture2D* CardImage;
#pragma endregion
};