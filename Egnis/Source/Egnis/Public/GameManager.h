#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoardPlayerController.h"
#include "BattleManager.h"
#include "GameManager.generated.h"

UCLASS()
class EGNIS_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GameManager")
	ABoardPlayerController* PlayerController = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameManager")
	UBattleManager* BattleManager = nullptr;
	
protected:
	virtual void BeginPlay() override;
	
private:
	void InitializeManagers();
};