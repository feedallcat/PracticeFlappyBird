// Fill out your copyright notice in the Description page of Project Settings.


#include "WaitingScreen.h"
#include "CommonButtonBase.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"

void UWaitingScreen::NativeConstruct() {
	Super::NativeConstruct();
	if (BTN_StartGame) {
		BTN_StartGame->OnClicked().AddUObject(this, &UWaitingScreen::OnStartGameClicked);
	}
}

void UWaitingScreen::NativeDestruct() {
	if (BTN_StartGame) {
		BTN_StartGame->OnClicked().RemoveAll(this);
	}
	Super::NativeDestruct();
}

void UWaitingScreen::OnStartGameClicked() {
	if (auto* GM = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode())) {
		GM->StartGame();
	}
}