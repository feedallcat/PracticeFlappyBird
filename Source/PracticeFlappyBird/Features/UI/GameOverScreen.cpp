// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverScreen.h"
#include "CommonButtonBase.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"

void UGameOverScreen::NativeConstruct() {
	Super::NativeConstruct();
	if (BTN_Restart) {
		BTN_Restart->OnClicked().AddUObject(this, &UGameOverScreen::OnRestartClicked);
	}
}

void UGameOverScreen::NativeDestruct() {
	if (BTN_Restart) {
		BTN_Restart->OnClicked().RemoveAll(this);
	}
}

void UGameOverScreen::OnRestartClicked() {
	if (auto* GM = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode())) {
		GM->RestartGame();
	}
}