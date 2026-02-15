#include "BoardPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "DrawDebugHelpers.h"

ABoardPlayerController::ABoardPlayerController()
{
	bShowMouseCursor = true;
	//bEnableClickEvents = true;
	//bEnableMouseOverEvents = true;
}

void ABoardPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);
	
	// Obtener sistema que gestiona el InputMappingContext
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (IMCGameplay)
				Subsystem->AddMappingContext(IMCGameplay, 0);
			if (IMCUI)
				Subsystem->AddMappingContext(IMCUI, 1);	// Mayor prioridad
		}
	}
}

// Asignar controles
void ABoardPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	if (!EnhancedInput) return;
	//check(EnhancedInput);

	//check(ClickAction);
	if (!ClickAction || !PauseAction)
	{
		UE_LOG(LogTemp, Warning, TEXT("ClickAction or PauseAction not found"));
		return;
	}
	EnhancedInput->BindAction(ClickAction, 
		ETriggerEvent::Started, 
		this, 
		&ABoardPlayerController::HandleLeftClick
	);
	EnhancedInput->BindAction(
			PauseAction,
			ETriggerEvent::Started,
			this,
			&ABoardPlayerController::HandleMenu
	);
}

// Interacción con click izquierdo
void ABoardPlayerController::HandleLeftClick()
{
	if (bIsInMenu) return;
	
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

// Gestionar controles cuando se abre un menu (ya sea de pausa, tutorial, etc.)
void ABoardPlayerController::OpenMenu()	// De momento solo el de pausa, en un futuro se pueden aniadir mas
{
	UE_LOG(LogTemp, Warning, TEXT("OpenMenu"));	// TODO: Borrar al final
	bIsInMenu = true;
	
	// Desactivar InputMappingContext
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->RemoveMappingContext(IMCGameplay);
		}
	}
	
	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);
}

void ABoardPlayerController::CloseMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("CloseMenu"));	// TODO: Borrar al final
	bIsInMenu = false;
	
	// Activar InputMappingContext
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(IMCGameplay, 0);
		}
	}
	
	SetInputMode(FInputModeGameAndUI());
}

void ABoardPlayerController::HandleMenu()
{
	bIsInMenu ? CloseMenu() : OpenMenu();
}