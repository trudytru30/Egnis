#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EGNIS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float ApplyDelta(float Delta);
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float GetCurrentHealt() {return CurrentHealth;}

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetMaxHealt() {return MaxHealth;}

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float MaxHealth = 100;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float CurrentHealth = 100;

	bool bDead = false;
	
private:
	void OnDeath();
};