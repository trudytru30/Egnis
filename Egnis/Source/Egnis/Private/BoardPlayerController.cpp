// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


ABoardPlayerController::ABoardPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void ABoardPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void ABoardPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	check(EnhancedInput);

	check(ClickAction);
	EnhancedInput->BindAction(ClickAction, ETriggerEvent::Started, this, &ABoardPlayerController::HandleLeftClick);
}

void ABoardPlayerController::HandleLeftClick()
{
	FClickResult Result;

	const ECollisionChannel UnitChannel  = UnitTraceChannel;
	const ECollisionChannel BoardChannel  = BoardTraceChannel;

	FHitResult Hit;

	if (CurrentIntent == EInputIntent::Action)
	{
		if (TraceUnderCursor(UnitChannel, Hit))
		{
			Result.bHit =true;
			Result.bHitUnit = true;
			Result.HitActor = Hit.GetActor();
			Result.WorldPoint = Hit.ImpactPoint;
		}
	}

	else //Movement
	{
		if (TraceUnderCursor(BoardChannel, Hit))
		{
			Result.bHit =true;
			Result.bHitBoard = true;
			Result.HitActor = Hit.GetActor();
			Result.WorldPoint = Hit.ImpactPoint;
		}
	}
		
	// Debug rápido
	if (GEngine)
	{
		const FString ModeStr = (CurrentIntent == EInputIntent::Action) ? TEXT("Action") : TEXT("Move");
		const FString HitStr =
			(!Result.bHit) ? TEXT("Nothing") :
			(Result.bHitUnit ? TEXT("Unit") : TEXT("Board"));

		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green,
			FString::Printf(TEXT("Mode=%s | Hit=%s | Actor=%s"),
				*ModeStr, *HitStr, Result.HitActor ? *Result.HitActor->GetName() : TEXT("None")));
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Cyan, TEXT("IA_Click triggered"));
	}
	
	if (Result.bHit)
	{
		DrawDebugSphere(GetWorld(), Result.WorldPoint, 10.f, 12, FColor::Green, false, 1.0f);
	}

	BP_OnclickResolved(Result);
}

bool ABoardPlayerController::TraceUnderCursor(ECollisionChannel Channel, FHitResult& OutHit) const
{
		FVector WorldOrigin, WorldDirection;
		if (!DeprojectMousePositionToWorld(WorldOrigin, WorldDirection))
		{
			return false;
		}

		const float TraceDistance = 200000.f;
		const FVector Start = WorldOrigin;
		const FVector End = WorldOrigin + (WorldDirection * TraceDistance);

		// Debug line (siempre)
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 1.5f);

		FCollisionQueryParams Params(SCENE_QUERY_STAT(ClickTrace), true);
		const bool bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, Params);

		if (bHit)
		{
			DrawDebugSphere(GetWorld(), OutHit.ImpactPoint, 12.f, 12, FColor::Green, false, 2.0f);
		}

		return bHit;
}



