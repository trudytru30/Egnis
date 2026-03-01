#pragma once

#include "CoreMinimal.h"
#include "BattleManager.generated.h"

class AAlly;
struct FTileCoord;
class UDeckManager;
class UBaseCard;
class ACharacterBase;
class AEnemy;

// Enumerador de los posibles turnos
UENUM()
enum class ETurnEnum { PlayerTurn = 0, EnemyTurn = 1 };	// Para poder aniadir otros tipos en el futuro

UCLASS()
class EGNIS_API UBattleManager : public UObject
{
	GENERATED_BODY()
	
public:
	
#pragma region Functions
	void Initialize(UDeckManager* DeckManager);
	void StartBattle();
	void StartPlayerTurn();
	void StartEnemyTurn();
	void EndTurn();
	bool PlayCard(UBaseCard* Card, AAlly* Character, ACharacterBase* TargetCharacter, FVector Location);
	void UpdateUnitsAlive();
	void EndBattle(bool bPlayerWon);
	UFUNCTION(BlueprintCallable, Category="Battle|Player")
	bool RequestMove(ACharacterBase* Unit, const FTileCoord& TargetTile);
	// Getters
	int32 GetTurnCount() const;
	TArray<ACharacterBase*> GetCharactersOnField() const;
	UFUNCTION(BlueprintPure)
	bool IsPlayerTurn() const;
#pragma endregion
	
private:
	
#pragma region Private Variables
	// ===== Managers =====
	UPROPERTY()
	UDeckManager* DeckManager;
	
	// ===== Turn System =====
	int32 TurnCount = 0;
	ETurnEnum CurrentTurn = ETurnEnum::PlayerTurn;
	
	// ===== Units =====
	UPROPERTY()
	TArray<ACharacterBase*> CharactersOnField;
#pragma endregion
};