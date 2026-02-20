// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PELEAMELEE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float ApplyDelta(float Delta);
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float GetCurrentHealt() {return CurrentHealth;}

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetMaxHealt() {return MaxHealth;}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float MaxHealth = 100;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float CurrentHealth = 100;

	bool bDead = false;

private:
	void BroadcastHealth();
	void OnDeath();
};
