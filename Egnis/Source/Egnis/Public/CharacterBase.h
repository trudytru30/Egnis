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
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHealthComponent* HealthComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColorType Type;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
