// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FTPlayer.generated.h"

UCLASS()
class PROJECTFISHING_API AFTPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AFTPlayer();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Move(const FInputActionValue& Value);

protected:
	void FindInteractable();
	void FocusInteractable(class IFTInteractable* newInteractable);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interact)
	float InteractRadius = 10;

	class IFTInteractable* FocusedInteractable;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<class UInputMappingContext> IMC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> InteractAction;

//protected:
//	UPROPERTY(Transient)
//	FRotator CameraRotation;
};
