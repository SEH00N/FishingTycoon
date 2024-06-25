// Fill out your copyright notice in the Description page of Project Settings.


#include "FTPlayer.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Core/FTPlayerController.h"
#include <Kismet/GameplayStatics.h>
#include <Core/FTCollision.h>
#include <Interface/FTInteractable.h>
#include "UI/FTWidgetComponent.h"
#include "UI/FTInteractPanel.h"

// Sets default values
AFTPlayer::AFTPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Game/FishingTycoon/Characters/Woowakgood.Woowakgood"));
	if (CharacterMeshRef.Object)
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);

	InteractPanelComponent = CreateDefaultSubobject<UFTWidgetComponent>(TEXT("InteractPanel"));
	InteractPanelComponent->SetupAttachment(GetMesh());
	InteractPanelComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -550.0f));

	static ConstructorHelpers::FClassFinder<UUserWidget> InteractPanelRef(TEXT("/Game/FishingTycoon/UI/WBP_InteractPanel.WBP_InteractPanel_C"));
	if (InteractPanelRef.Class)
	{
		InteractPanelComponent->SetWidgetClass(InteractPanelRef.Class);
		InteractPanelComponent->SetWidgetSpace(EWidgetSpace::Screen);
		InteractPanelComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AFTPlayer::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(IMC, 0);
	}
}

void AFTPlayer::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	FindInteractable();
}

void AFTPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFTPlayer::Move);
	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AFTPlayer::Interact);
}

void AFTPlayer::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementVector.Normalize();

	FVector MoveDirection = FVector(MovementVector.X, MovementVector.Y, 0.0f);
	FRotator Rotator = FRotator(0, -90, 0);
	AddMovementInput(Rotator.RotateVector(MoveDirection));
}

void AFTPlayer::Interact(const FInputActionValue& Value)
{
	if (FocusedInteractable == nullptr)
		return;

	FocusedInteractable->OnInteract(this);
}

void AFTPlayer::FindInteractable()
{
	const FVector Position = GetActorLocation();
	TArray<FOverlapResult> OverlapResults;
	IFTInteractable* interactable = nullptr;

	bool bFound = GetWorld()->OverlapMultiByChannel(OverlapResults, Position, FQuat::Identity, CCHANNEL_FTINTERACT, FCollisionShape::MakeSphere(InteractRadius));

	if (bFound)
		interactable = Cast<IFTInteractable>(OverlapResults[0].GetActor());

	if (interactable != FocusedInteractable)
		FocusInteractable(interactable);

#if ENABLE_DRAW_DEBUG
	FColor DrawColor = bFound ? FColor::Green : FColor::Red;
	DrawDebugSphere(GetWorld(), Position, InteractRadius, 8, DrawColor);
#endif
}

void AFTPlayer::FocusInteractable(IFTInteractable* newInteractable)
{
	if (FocusedInteractable)
	{
		FocusedInteractable->OnFocusEnd(this);
		InteractPanel->Display(false);
	}
	FocusedInteractable = newInteractable;
	if (FocusedInteractable)
	{
		FocusedInteractable->OnFocusBegin(this);
		InteractPanel->Init(FocusedInteractable->GetTooltip());
		InteractPanel->Display(true);
	}
}

void AFTPlayer::InitWidget(UFTUserWidget* FTWidget)
{
	InteractPanel = Cast<UFTInteractPanel>(FTWidget);
}
