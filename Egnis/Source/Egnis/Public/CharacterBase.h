#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ColorType.h"
#include "HealthComponent.h"
#include "CharacterBase.generated.h"

UCLASS()
class EGNIS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UHealthComponent* HealthComp = nullptr;
	
	// ===== Funciones =====
	UFUNCTION(BlueprintCallable, Category="Stats")
	void LossHealth(float HealthToLoss);
	
	UFUNCTION(BlueprintCallable, Category="Stats")
	void GainHealth(float AmountHealed);
	
	UFUNCTION(BlueprintCallable, Category="Stats")
	int32 GetTeam();
	
protected:
	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColorType Type;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats", meta=(AllowPrivateAccess=true))
	int32 Team = 0;	// 0 para el jugador, 1 para los enemigos, etc.
};