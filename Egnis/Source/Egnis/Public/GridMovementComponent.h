// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Board.h"
#include "GridMovementComponent.generated.h"


/*
 * Para prototipo partimos de un mov de 8 dir como base ( primer personaje)
 **/
UENUM(BlueprintType)
enum class EMovePattern : uint8
{
	Straight_WBlock UMETA(DisplayName="Recto 8 dir con bloaqueo"),
	Straight_CanPass UMETA(DisplayName="Recto 8 dir sin bloqueo")//ignora obstaculos
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EGNIS_API UGridMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGridMovementComponent();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	int32 moveRange=4;//maximo de casillas a recorrer (oso)

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	EMovePattern movePattern=EMovePattern::Straight_WBlock;//patron actual

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	TObjectPtr<ABoard>BoardActor=nullptr;//ref para el tablero

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool getCurrentTile(FTileCoord& OutTile);//devuelve la casilla actual

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void getRachableTiles(TArray<FTileCoord>& OutTiles);//calcula las casillas segun el patron y rango de mov

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool canMoveToTile(const FTileCoord& Target);//mira si la casilla esta dentro de los limites

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool moveToTile(const FTileCoord& Target);//nos devuelve true si se mueve

private:
	void EnsureBoardActor();//comprueba que este
	bool IsTileValid(const FTileCoord& T);//mira que este dentro de limites tablero

	
protected:
	virtual void BeginPlay() override;
};
