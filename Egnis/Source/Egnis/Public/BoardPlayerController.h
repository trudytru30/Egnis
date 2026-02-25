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

	UPROPERTY(BlueprintReadWrite) bool  bHit = false;
	UPROPERTY(BlueprintReadWrite) bool  bHitUnit = false;
	UPROPERTY(BlueprintReadWrite) bool  bHitBoard = false;

	UPROPERTY(BlueprintReadWrite) TObjectPtr<class AActor> HitActor = nullptr;
	UPROPERTY(BlueprintReadWrite) FVector WorldPoint = FVector::ZeroVector;
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

#pragma region Input
	UFUNCTION(BlueprintImplementableEvent, Category="Input")
	void BP_OnclickResolved(const FClickResult& Result);
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> IMCGameplay;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> IMCUI;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> PauseAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> ClickAction ;
#pragma endregion
	
	UPROPERTY(EditDefaultsOnly, Category="Click|Trace")
	TEnumAsByte<ECollisionChannel> UnitTraceChannel = ECC_GameTraceChannel1;

	UPROPERTY(EditDefaultsOnly, Category="Click|Trace")
	TEnumAsByte<ECollisionChannel> BoardTraceChannel = ECC_GameTraceChannel2;

private:
	
	bool bIsInMenu = false;
	
	void OpenMenu();
	void CloseMenu();
	void HandleMenu();
	void HandleLeftClick();
	bool TraceUnderCursor(ECollisionChannel Channel, FHitResult& OutHit ) const;
};