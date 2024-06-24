// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/FTInteractable.h"
#include "FTShop.generated.h"

UCLASS()
class PROJECTFISHING_API AFTShop : public AActor, public IFTInteractable
{
	GENERATED_BODY()
	
public:	
	AFTShop();

public:	
	void OnInteract(AActor* performer) override;
	void OnFocusBegin(AActor* performer) override;
	void OnFocusEnd(AActor* performer) override;
};
