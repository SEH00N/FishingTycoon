// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FTInteractable.generated.h"

UINTERFACE(MinimalAPI)
class UFTInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTFISHING_API IFTInteractable
{
	GENERATED_BODY()

public:
	virtual void OnInteract(AActor* Performer) abstract;
	virtual void OnFocusBegin(AActor* Performer) abstract;
	virtual void OnFocusEnd(AActor* Performer) abstract;
	virtual FString& GetTooltip() abstract;
};
