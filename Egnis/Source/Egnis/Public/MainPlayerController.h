#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class EGNIS_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	void HandleLeftClick();
	
#pragma region Input Actions
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* IMCGameplay;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* IMCUI;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LeftClickAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* PauseAction;
#pragma endregion
	
private:
	bool bIsInMenu = false;
	
	void OpenMenu();
	void CloseMenu();
	void HandleMenu();
};