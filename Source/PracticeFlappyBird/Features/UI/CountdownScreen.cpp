// Fill out your copyright notice in the Description page of Project Settings.


#include "CountdownScreen.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "CommonTextBlock.h"

void UCountdownScreen::NativeConstruct() {
	Super::NativeConstruct();

	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnCountdownUpdated.AddDynamic(this, &UCountdownScreen::OnCountdownUpdated);
		OnCountdownUpdated(3.0f);
	}
}

void UCountdownScreen::NativeDestruct() {
	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnCountdownUpdated.RemoveDynamic(this, &UCountdownScreen::OnCountdownUpdated);
	}
	Super::NativeDestruct();
}

void UCountdownScreen::OnCountdownUpdated(float Time) {
	if (CTB_Countdown) {
		CTB_Countdown->SetText(FText::Format(NSLOCTEXT("UGameHUDScreen", "Countdown", "Game Start in: {0}"), FText::AsNumber(Time)));
	}
}