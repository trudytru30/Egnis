// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyComponent.h"


// Sets default values for this component's properties
UEnergyComponent::UEnergyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UEnergyComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentPoints = FMath::Clamp(CurrentPoints, 0.0f, MaxPoints); //clampea valores de los puntos
	
}

int32 UEnergyComponent::ApplyDelta(int32 Delta)
{
	CurrentPoints += Delta; //por si a futuro se quiren cartas que sumen puntos de energia
	return CurrentPoints;
}

int32 UEnergyComponent::ResetPoints()
{
	CurrentPoints = MaxPoints;
	return CurrentPoints;
}

