#include "Board.h"

#include "Internationalization/TextPackageNamespaceUtil.h"

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
bool ABoard::IsTileOccupied(const FTileCoord& Tile) const
{
	if (!IsInside(Tile))
	{
		return true; // fuera del tablero se considera no caminable
	}
	
	if (const TWeakObjectPtr<AActor>* Found = OccupiedBy.Find(Tile))
	{
			return Found->IsValid();
	}

	return false;
}

bool ABoard::RegisterOccupant(const FTileCoord& Tile, AActor* Occupant)
{
	if(IsTileOccupied(Tile))
	{
		return false;
	}
	OccupiedBy.Add(Tile, Occupant);
	return true;
	
}

void ABoard::UnregisterOccupant(const FTileCoord& Tile, AActor* Occupant)
{
	if (!IsInside(Tile) || !Occupant)
	{
		return;
	}

	if (const TWeakObjectPtr<AActor>* Found = OccupiedBy.Find(Tile) )
	{
		if (Found->Get() == Occupant)
		{
			OccupiedBy.Remove(Tile);
		}
	}
}

void ABoard::GetNeighbors4_Free(const FTileCoord& From, TArray<FTileCoord>& OutNeighbors) const
{
	OutNeighbors.Reset();

	const FTileCoord Candidates[4]={
		FTileCoord{From.X+1,From.Y},
		FTileCoord{From.X-1,From.Y},
		FTileCoord{From.X,From.Y+1},
		FTileCoord{From.X, From.Y-1}
		};

	for (const FTileCoord& Candidate : Candidates)
	{
		if (IsInside(Candidate) && !IsTileOccupied(Candidate))
		{
			OutNeighbors.Add(Candidate);
		}
	}
}

AActor* ABoard::GetTileOccupant(const FTileCoord& Tile) const
{
	const TObjectPtr<AActor>* Found = TileOccupants.Find(Tile);
	return Found ? Found->Get() : nullptr;
}

void ABoard::SetTileOccupant(const FTileCoord& Tile, AActor* Occupant)
{
	if (Occupant)
	{
		TileOccupants.Add(Tile, Occupant);
	}
	else
	{
		TileOccupants.Remove(Tile);
	}
}

bool ABoard::IsInside(const FTileCoord& Tile) const
{
	return Tile.X >= 0 && Tile.X < BoardSizeX && Tile.Y >= 0 && Tile.Y < BoardSizeY;
}

void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}