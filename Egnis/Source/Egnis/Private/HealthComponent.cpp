#include "HealthComponent.h"

#include "CharacterBase.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);
	
}

float UHealthComponent::ApplyDelta(float Delta)
{
	if (Delta == 0.0f)
	{
		return CurrentHealth;
	}

	const float OldHealth = CurrentHealth;
	CurrentHealth  = FMath::Clamp(CurrentHealth+Delta,0.0f,MaxHealth);

	//Si el delta es por daño y no por curacion
	const bool bDamageApplied = (Delta < 0.0f) && (CurrentHealth < OldHealth);

	//Si no nos mata aplicamos hitReact
	if (bDamageApplied && CurrentHealth > 0.0f)
	{
		//queu visaul al jugador de daño
	}

	//Si nos mata aplicamos Death
	if (OldHealth > 0.0f &&  CurrentHealth <=0.0f)
	{
		OnDeath();
	}

	return CurrentHealth;
}

void UHealthComponent::OnDeath()
{
	bDead = true;
	ACharacterBase* Owner = GetOwner<ACharacterBase>();
	Owner->EndPlay(EEndPlayReason::Destroyed);
}
