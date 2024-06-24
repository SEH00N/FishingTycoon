// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FTInteractPanel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFISHING_API UFTInteractPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFTInteractPanel(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
	TObjectPtr<class UTextBlock> Text;

public:
	void Init(FVector2D& Position, FString& Tooltip);
	void Display(class IInteractable* Performer, bool Active);

protected:
	class IInteractable* CurrentInteractable;
};
