#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "GridMovementComponent.h"
#include "GameFramework/Character.h"
#include "Ally.generated.h"

UCLASS()
class EGNIS_API AAlly : public ACharacterBase
{
	GENERATED_BODY()

public:
	AAlly();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void LossPoints(int32 Cost);
	void GainPoints(int32 Bonus);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UEnergyComponent* EnergyComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UGridMovementComponent* MoveComp;
	
protected:
	virtual void BeginPlay() override;
};