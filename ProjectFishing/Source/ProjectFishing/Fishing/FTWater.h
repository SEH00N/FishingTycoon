// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/FTInteractable.h"
#include "FTWater.generated.h"

UCLASS()
class PROJECTFISHING_API AFTWater : public AActor, public IFTInteractable
{
	GENERATED_BODY()
	
public:
	AFTWater();
	virtual void BeginPlay() override;

public:
	FString& Tooltip = FString(TEXT("³¬½ÃÇÏ±â"));
	
	void OnInteract(AActor* Performer) override;
	void OnFocusBegin(AActor* Performer) override;
	void OnFocusEnd(AActor* Performer) override;
	FString& GetTooltip() override { return Tooltip; }

};
