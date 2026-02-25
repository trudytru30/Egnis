#pragma once

#include "CoreMinimal.h"
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
	void TurnChange();
	
protected:
	
#pragma region Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	TArray<ACharacterBase*> CharactersOnField;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	TArray<ACharacterBase*> AlliesAlive;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	int32 UnitsAlive;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	TArray<UBaseCard*> Deck;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BattleManager")
	int32 TurnNumber = 0;
#pragma endregion
	
private:
	ETurnEnum CurrentTurn = ETurnEnum::PlayerTurn;
	
	// ===== Funciones =====
	void UpdateUnitsAlive();
	
};