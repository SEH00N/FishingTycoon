// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FTHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFISHING_API UFTHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFTHUD(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;
};
