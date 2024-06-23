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
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
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
	FindInteractable();
}

void AFTPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFTPlayer::Move);
}

void AFTPlayer::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementVector.Normalize();

	FVector MoveDirection = FVector(MovementVector.X, MovementVector.Y, 0.0f);
	FRotator Rotator = FRotator(0, -90, 0);
	AddMovementInput(Rotator.RotateVector(MoveDirection));
	//AddMovementInput(MoveDirection);

	//GetController()->SetControlRotation(FRotationMatrix::MakeFromX(MoveDirection).Rotator());

	UE_LOG(LogTemp, Log, TEXT("Quater Move"));
}

void AFTPlayer::FindInteractable()
{
	const FVector Position = GetActorLocation();
	TArray<FOverlapResult> OverlapResults;

	bool bFound = GetWorld()->OverlapMultiByChannel(OverlapResults, Position, FQuat::Identity, CCHANNEL_FTINTERACTABLE, FCollisionShape::MakeSphere(InteractRadius));

	if (bFound)
	{
		IFTInteractable* interactable = Cast<IFTInteractable>(OverlapResults[0].GetActor());
		if (interactable)
			interactable->OnInteract(this);
	}

#if ENABLE_DRAW_DEBUG
	FColor DrawColor = bFound ? FColor::Green : FColor::Red;
	DrawDebugSphere(GetWorld(), Position, InteractRadius, 8, DrawColor);
#endif
}
