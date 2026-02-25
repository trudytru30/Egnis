#pragma once

#include "CoreMinimal.h"
#include "DeckManager.h"
#include "BattleManager.generated.h"

class UBaseCard;
class ACharacterBase;

// Enumerador de los posibles turnos
UENUM()
enum ETurnEnum { PlayerTurn, EnemyTurn };	// Para poder aniadir otros tipos en el futuro

UCLASS()
class EGNIS_API UBattleManager : public UObject
{
	GENERATED_BODY()

public:
	
	void StartBattle();
	
protected:

#pragma region Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	int32 CharactersOnField = 1;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	TArray<ACharacterBase*> AlliesAlive;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	TArray<ACharacterBase*> EnemiesAlive;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	UDeckManager* DeckManager;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	int32 TurnNumber = 0;
#pragma endregion
	
private:
	
#pragma region Inner Variables
	ETurnEnum CurrentTurn = ETurnEnum::PlayerTurn;
	bool bEndTurn = false;
#pragma endregion

#pragma region Inner Functions
	void TurnChange();
	void UpdateUnitsAlive();
	void StartPlayerTurn();
	void StartEnemyTurn();
	void EndBattle(int Team);
#pragma endregion
};