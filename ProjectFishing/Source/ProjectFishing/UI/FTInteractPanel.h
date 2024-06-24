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
	void Init(FString& Tooltip);
	void SetPosition(FVector2D& Position);
	void Display(class IFTInteractable* Performer, bool Active);

protected:
	class IFTInteractable* CurrentInteractable;
};
