// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseScreen.h"
#include "CommonButtonBase.h"
#include "PracticeFlappyBird/Features/Input/Player/FlappyBirdPlayerController.h"

void UPauseScreen::NativeConstruct()
{
	Super::NativeConstruct();
	if (BTN_Resume)
	{
		BTN_Resume->OnClicked().AddUObject(this, &UPauseScreen::OnResumeBtnClicked);
	}
}

void UPauseScreen::NativeDestruct()
{
	if (BTN_Resume)
	{
		BTN_Resume->OnClicked().RemoveAll(this);
	}
	Super::NativeDestruct();
}

bool UPauseScreen::NativeOnHandleBackAction()
{
	UE_LOG(LogTemp, Warning, TEXT("Back Action Pressed on Pause Menu!!!"));
	if(auto* PC = GetOwningPlayer<AFlappyBirdPlayerController>())
	{
		PC->RequestPause();
		return true;
	}
	return false;
}

void UPauseScreen::OnResumeBtnClicked()
{
	if (auto* PC = GetOwningPlayer<AFlappyBirdPlayerController>())
	{
		PC->RequestPause();
	}
}