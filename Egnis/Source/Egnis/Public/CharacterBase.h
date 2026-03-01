#pragma once

#include "CoreMinimal.h"
#include "Board.h"
#include "GameFramework/Character.h"
#include "ColorType.h"
#include "HealthComponent.h"
#include "CharacterBase.generated.h"

class UEnergyComponent;

UCLASS()
class EGNIS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UHealthComponent* HealthComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UEnergyComponent* EnergyComp = nullptr;

	// ===== Funciones =====
	UFUNCTION(BlueprintCallable, Category="Stats")
	void LossHealth(float HealthToLoss);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void GainHealth(float AmountHealed);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void LossPoints(int32 Cost);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void GainPoints(int32 Bonus);
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UFUNCTION(BlueprintCallable, Category="Stats")
	int32 GetTeam();

	// ===== Grid / Board =====

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grid")
	TObjectPtr<ABoard> Board = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Grid")
	FTileCoord CurrentTile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Grid")
	bool bSnapToTileOnBeginPlay = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Grid")
	float TileZOffset = 0.f;

	UFUNCTION(BlueprintCallable, Category="Grid")
	bool SetCurrentTile(const FTileCoord& NewTile);

	UFUNCTION(BlueprintCallable, Category="Grid")
	void SnapToCurrentTile(bool bKeepCurrentZ = false);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColorType Type;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Team")
	int32 Team = 0; // 0 para el jugador, 1 para los enemigos, etc.
};