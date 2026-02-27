// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

enum class EActionId : uint8;
class UActionDataAsset;
class UEnemyArchetypeDataAsset;

UCLASS()
class EGNIS_API AEnemy : public ACharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Selecionar Arquetipo
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Enemy|Data")
	TObjectPtr<UEnemyArchetypeDataAsset> ArchetypeData = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category ="Enemy|AI")
	bool bDebugMovementOnBeginPlay = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enemy|Combat")
	float AttackDamage = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Enemy|Combat")
	float HealAmount = 8.f;

	UFUNCTION(BlueprintCallable, Category ="Enemy|AI")
	void MoveTowardClosesPlayer();

	UFUNCTION(BlueprintCallable, Category ="Enemy|AI")
	void MakeAction();

	UFUNCTION(BlueprintCallable,Category = "Enemy|Actions")
	const UActionDataAsset* GetActionById(EActionId ActionId) const;

private:

	ACharacterBase* FindClosestPlayer() const;
	static int32 ManhattanDistance(const FTileCoord& A, const FTileCoord& B);

	ACharacterBase* FindBestTarget(int32 _Range, int32 _BestRatio, int32 _Team);
};
