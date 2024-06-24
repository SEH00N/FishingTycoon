// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FTPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFISHING_API AFTPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void virtual BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HUD)
	TSubclassOf<class UFTHUD> FTHUDWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HUD)
	TObjectPtr<class UFTHUD> FTHUD;
};
