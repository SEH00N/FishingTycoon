// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FTUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFISHING_API UFTUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void Init(AActor* Owner);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Actor)
	TObjectPtr<AActor> OwningActor;
};
