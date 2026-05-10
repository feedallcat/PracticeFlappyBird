// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDScreen.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Core/PlayerState/MyPlayerState.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "CommonTextBlock.h"

void UGameHUDScreen::NativeConstruct() {
	Super::NativeConstruct();

	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &UGameHUDScreen::OnGameStateChanged);
	}

	if (auto* PC = GetOwningPlayer()) {
		if (auto* PS = PC->GetPlayerState<AMyPlayerState>()) {
			PS->OnPlayerScoreChanged.AddDynamic(this, &UGameHUDScreen::OnPlayerScoreChanged);
			UpdateScore(PS->PlayerScore);
		}
		if (auto* PP = Cast<APlayerPaperCharacter>(PC->GetPawn())) {
			PP->OnPlayerStatusChanged.AddDynamic(this, &UGameHUDScreen::OnPlayerStatusChanged);
		}
	}
}

void UGameHUDScreen::NativeDestruct() {
	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.RemoveDynamic(this, &UGameHUDScreen::OnGameStateChanged);
	}
	if (auto* PC = GetOwningPlayer()) {
		if (auto* PS = PC->GetPlayerState<AMyPlayerState>()) {
			PS->OnPlayerScoreChanged.RemoveDynamic(this, &UGameHUDScreen::OnPlayerScoreChanged);
		}
		if (auto* PP = Cast<APlayerPaperCharacter>(PC->GetPawn())) {
			PP->OnPlayerStatusChanged.RemoveDynamic(this, &UGameHUDScreen::OnPlayerStatusChanged);
		}
	}
	Super::NativeDestruct();
}

void UGameHUDScreen::UpdateScore(int32 Score) {
	if (CTB_Score)
	{
		CTB_Score->SetText(FText::Format(NSLOCTEXT("UGameHUDScreen", "ScoreText", "Score: {0}"), FText::AsNumber(Score)));
	}
}

void UGameHUDScreen::OnGameStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		break;
	case EMainGameState::Countdown:
		break;
	case EMainGameState::Started:
		break;
	case EMainGameState::GameOver:
		break;

	default:
		break;
	}
}

void UGameHUDScreen::OnPlayerStatusChanged(EPlayerStatus NewStatus) {
	switch (NewStatus) {
	case EPlayerStatus::Alive:
		break;
	case EPlayerStatus::Dead:
		break;
	default:
		break;
	}
}

void UGameHUDScreen::OnPlayerScoreChanged(int32 NewScore) {
	UpdateScore(NewScore);
}