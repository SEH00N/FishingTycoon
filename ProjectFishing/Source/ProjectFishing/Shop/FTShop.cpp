// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop/FTShop.h"
#include "Core/FTPlayerController.h"
#include "UI/FTHUD.h"
#include "UI/FTInteractPanel.h"

AFTShop::AFTShop()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFTShop::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<AFTPlayerController>(GetWorld()->GetFirstPlayerController());
	//InteractPanel = PlayerController->GetFTHUD()->GetInteractPanel();
}

void AFTShop::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bIsFocused == false)
		return;

	SetPanelPosition();
}

void AFTShop::SetPanelPosition()
{
	FVector2D ScreenPosition;
	PlayerController->ProjectWorldLocationToScreen(CurrentPerformer->GetActorLocation(), ScreenPosition);
	FString string = ScreenPosition.ToString();
	UE_LOG(LogTemp, Log, TEXT("%s"), *string);
	
	InteractPanel->SetPosition(ScreenPosition);
}

void AFTShop::OnInteract(AActor* Performer)
{
	UE_LOG(LogTemp, Log, TEXT("Interacted"));
}

void AFTShop::OnFocusBegin(AActor* Performer)
{
	UE_LOG(LogTemp, Log, TEXT("Focus Begin"));
	if (InteractPanel == nullptr)
		InteractPanel = PlayerController->GetFTHUD()->GetInteractPanel();
	
	CurrentPerformer = Performer;
	bIsFocused = true;

	SetPanelPosition();
	InteractPanel->Init(Tooltip);
	InteractPanel->Display(this, true);
}

void AFTShop::OnFocusEnd(AActor* Performer)
{
	UE_LOG(LogTemp, Log, TEXT("Focus End"));
	PlayerController->GetFTHUD()->GetInteractPanel()->Display(this, false);
	bIsFocused = false;
	CurrentPerformer = nullptr;
}

