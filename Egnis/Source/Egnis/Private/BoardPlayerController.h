// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BoardPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

UENUM(BlueprintType)
enum class EInputIntent: uint8
{
	Move,
	Action
};

USTRUCT(BlueprintType)
struct FClickResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintreadWrite) bool  bHit = false;
	UPROPERTY(BlueprintreadWrite) bool  bHitUnit = false;
	UPROPERTY(BlueprintreadWrite) bool  bHitBoard = false;

	UPROPERTY(BlueprintreadWrite) TObjectPtr<class AActor> HitActor = nullptr;
	UPROPERTY(BlueprintreadWrite) FVector WorldPoint = FVector::ZeroVector;
};

UCLASS()
class EGNIS_API ABoardPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABoardPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	EInputIntent CurrentIntent = EInputIntent::Move;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintImplementableEvent, Category="Input")
	void BP_OnclickResolved(const FClickResult& Result);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> ClickAction ;

	UPROPERTY(EditDefaultsOnly, Category="Click|Trace")
	TEnumAsByte<ECollisionChannel> UnitTraceChannel = ECC_GameTraceChannel1;

	UPROPERTY(EditDefaultsOnly, Category="Click|Trace")
	TEnumAsByte<ECollisionChannel> BoardTraceChannel = ECC_GameTraceChannel2;

private:
	void HandleLeftClick();
	bool TraceUnderCursor(ECollisionChannel Channel, FHitResult& OutHit ) const;
	
};
