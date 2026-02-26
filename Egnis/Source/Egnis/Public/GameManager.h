#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

class UBattleManager;
class UDeckManager;

UCLASS()
class EGNIS_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AGameManager();
	
protected:
	
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY()
	UDeckManager* DeckManager;
	
	UPROPERTY()
	UBattleManager* BattleManager;
	
	void InitializeManagers();
};