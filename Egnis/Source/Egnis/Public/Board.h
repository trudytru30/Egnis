// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

USTRUCT(BlueprintType)
struct FTileCoord
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly) int32 X = -1;
	UPROPERTY(BlueprintReadOnly) int32 Y = -1;
	
};

UCLASS()
class EGNIS_API ABoard : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoard();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Board)
	float TileSize = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Board)
	int32 BoardSizeX = 8;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Board)
	int32 BoardSizeY = 8;

	UFUNCTION(BlueprintCallable, Category = Board)
	bool WorldPointToTile(const FVector& WorldPoint, FTileCoord& OutTile) const;

	UFUNCTION(BlueprintCallable, Category="Board")
	FVector TileToWorldCenter(const FTileCoord& Tile) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = "Board")
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = "Board")
	TObjectPtr<USceneComponent> Corner00;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
