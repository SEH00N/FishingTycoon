// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Interface/FTWidgetHandler.h"
#include "FTPlayer.generated.h"

UCLASS()
class PROJECTFISHING_API AFTPlayer : public ACharacter, public IFTWidgetHandler
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
	void Interact(const FInputActionValue& Value);

protected:
	void FindInteractable();
	void FocusInteractable(class IFTInteractable* newInteractable);
	void InitWidget(UFTUserWidget* FTWidget) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Interact)
	TObjectPtr<class UFTWidgetComponent> InteractPanelComponent;
	class UFTInteractPanel* InteractPanel = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interact)
	float InteractRadius = 10;

	class IFTInteractable* FocusedInteractable = nullptr;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<class UInputMappingContext> IMC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> InteractAction;
};
