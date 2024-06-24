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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	class AFTPlayerController* PlayerController;
	class UFTInteractPanel* InteractPanel;
	class AActor* CurrentPerformer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Tooltip = FString(TEXT("SHOP"));

protected:
	bool bIsFocused = false;
	void SetPanelPosition();

public:	
	void OnInteract(AActor* Performer) override;
	void OnFocusBegin(AActor* Performer) override;
	void OnFocusEnd(AActor* Performer) override;
};
