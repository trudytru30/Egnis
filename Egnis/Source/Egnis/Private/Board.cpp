// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"


// Sets default values
ABoard::ABoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Corner00 = CreateDefaultSubobject<USceneComponent>(TEXT("Corner00"));
	Corner00->SetupAttachment(Root);
}

bool ABoard::WorldPointToTile(const FVector& WorldPoint, FTileCoord& OutTile) const
{
	const FVector Local = Corner00->GetComponentTransform().InverseTransformPosition(WorldPoint);

	//Redondea al entero más cercano
	const int32 X = FMath::FloorToInt(Local.X/TileSize);
	const int32 Y = FMath::FloorToInt(Local.Y/TileSize);

	const bool bValid = (X>=0 && X<BoardSizeX && Y >=0 && Y<BoardSizeY);

	if (!bValid)
	{
		OutTile = FTileCoord();
		return false;
	}

	OutTile.X = X;
	OutTile.Y = Y;
	return true;
}

FVector ABoard::TileToWorldCenter(const FTileCoord& Tile) const
{
	const FVector LocalCenter(
		(Tile.X+0.5f) * TileSize,
		(Tile.Y+0.5f) * TileSize,
		0.f
		);

	return Corner00->GetComponentTransform().TransformPosition(LocalCenter);
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}