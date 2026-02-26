// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnergyComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EGNIS_API UEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnergyComponent();

	UFUNCTION(BlueprintCallable, Category="Points")
	int32 ApplyDelta(int32 Delta);

	UFUNCTION(BlueprintCallable, Category="Points")
	int32 ResetPoints();
	
	UFUNCTION(BlueprintCallable, Category="Points")
	int32 GetCurrentPoints() {return CurrentPoints;}

	UFUNCTION(BlueprintCallable, Category="Points")
	int32 GetMaxPoints() {return MaxPoints;}

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Points")
	int32 MaxPoints = 6;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Points")
	int32 CurrentPoints = 6;
};
