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

FORCEINLINE bool operator==(const FTileCoord& A, const FTileCoord& B)
{
	return A.X == B.X && A.Y == B.Y;
}

FORCEINLINE uint32 GetTypeHash(const FTileCoord& T)
{
	return HashCombine(::GetTypeHash(T.X), ::GetTypeHash(T.Y));
}

UCLASS()
class EGNIS_API ABoard : public AActor
{
	GENERATED_BODY()

public:
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

	UFUNCTION(BlueprintCallable, Category="Board|Ocupacion")
	bool IsTileOccupied(const FTileCoord& Tile) const;

	UFUNCTION(BlueprintCallable, Category="Board|Ocupacion")
	AActor* GetTileOccupant(const FTileCoord& Tile) const;

	UFUNCTION(BlueprintCallable, Category="Board|Ocupacion")
	void SetTileOccupant(const FTileCoord& Tile, AActor* Occupant);

private:
	UPROPERTY()
	TMap<FTileCoord, TObjectPtr<AActor>> TileOccupants;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = "Board")
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = "Board")
	TObjectPtr<USceneComponent> Corner00;

public:
	virtual void Tick(float DeltaTime) override;
};