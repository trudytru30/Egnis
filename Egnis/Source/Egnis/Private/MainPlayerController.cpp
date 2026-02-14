#include "MainPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// Obtener sistema que gestiona el InputMappingContext
	if (UEnhancedInputLocalPlayerSubsystem *Subsystem = 
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (IMCGameplay)
			Subsystem->AddMappingContext(IMCGameplay, 0);
		if (IMCUI)
			Subsystem->AddMappingContext(IMCUI, 1);	// Mayor prioridad
	}
	
	bShowMouseCursor = true;
	SetInputMode(FInputModeGameAndUI());
	
	// TODO: Borrar al final
	UE_LOG(LogTemp, Warning, TEXT("IMCGameplay: %s"), IMCGameplay ? TEXT("OK") : TEXT("NULL"));
	UE_LOG(LogTemp, Warning, TEXT("IMCUI: %s"), IMCUI ? TEXT("OK") : TEXT("NULL"));
}

// Asignar controles
void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(
			LeftClickAction,
			ETriggerEvent::Started,
			this, 
			&AMainPlayerController::HandleLeftClick
		);
		EnhancedInput->BindAction(
			PauseAction,
			ETriggerEvent::Started,
			this,
			&AMainPlayerController::HandleMenu
		);
	}
}

// Interacción con click izquierdo
void AMainPlayerController::HandleLeftClick()
{
	if (bIsInMenu) return;
	
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	
	if (HitResult.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Warning, TEXT("Left Clicked on %s"), *HitResult.GetActor()->GetName());	// TODO: Sustituir por interaccion
	}
}

// Gestionar controles cuando se abre un menu (ya sea de pausa, tutorial, etc.)
void AMainPlayerController::OpenMenu()	// De momento solo el de pausa, en un futuro se pueden aniadir mas
{
	UE_LOG(LogTemp, Warning, TEXT("OpenMenu"));	// TODO: Borrar al final
	bIsInMenu = true;
	
	// Desactivar InputMappingContext
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->RemoveMappingContext(IMCGameplay);
	}
	
	SetInputMode(FInputModeUIOnly());
}

void AMainPlayerController::CloseMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("CloseMenu"));	// TODO: Borrar al final
	bIsInMenu = false;
	
	// Activar InputMappingContext
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMCGameplay, 0);
	}
	
	SetInputMode(FInputModeGameAndUI());
}

void AMainPlayerController::HandleMenu()
{
	if (bIsInMenu)
	{
		CloseMenu();
	} else
	{
		OpenMenu();
	}
}