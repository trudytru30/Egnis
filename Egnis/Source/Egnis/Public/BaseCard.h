#pragma once

#include "CoreMinimal.h"
#include "CardType.h"
#include "ColorType.h"
#include "BaseCard.generated.h"

UCLASS(BlueprintType)
class EGNIS_API UBaseCard : public UObject
{
	GENERATED_BODY()

protected:
	// ===== Stats =====
#pragma region Stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	ECardType CardType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	EColorType Color;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	int32 Cost;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	int32 Area;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	UTexture2D* CardImage;
#pragma endregion
	
	// ===== Funciones =====
	void Execute(ECardType CardType);
};