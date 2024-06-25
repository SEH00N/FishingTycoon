// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/FTUserWidget.h"
#include "FTInteractPanel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFISHING_API UFTInteractPanel : public UFTUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
	TObjectPtr<class UTextBlock> Text;

public:
	void Init(FString& Tooltip);
	void Display(bool Active);
};
