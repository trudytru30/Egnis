#pragma once

#include "CoreMinimal.h"
#include "BattleManager.generated.h"

class UDeckManager;
class UBaseCard;
class ACharacterBase;

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
	bool PlayCard(UBaseCard* Card, ACharacterBase* Character, ACharacterBase* TargetCharacter, FVector Location);
	void UpdateUnitsAlive();
	void EndBattle(bool bPlayerWon);
	// Getters
	int32 GetTurnCount() const;
	int32 GetCurrentEnergy() const;
	TArray<ACharacterBase*> GetCharactersOnField() const;
#pragma endregion
	
private:
	
#pragma region Variables
	// ===== Managers =====
	UPROPERTY()
	UDeckManager* DeckManager;
	
	// ===== Turn System =====
	UPROPERTY()
	int32 TurnCount = 0;
	ETurnEnum CurrentTurn = ETurnEnum::PlayerTurn;
	
	// ===== Energy System =====
	int32 MaxEnergy = 10;
	int32 InitialEnergy = 5;
	int32 CurrentEnergy = InitialEnergy;
	
	// ===== Units =====
	UPROPERTY()
	TArray<ACharacterBase*> CharactersOnField;
#pragma endregion
};