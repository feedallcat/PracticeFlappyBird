// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDUserWidget.h"
#include "Components/TextBlock.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Core/PlayerState/MyPlayerState.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"

void UGameHUDUserWidget::NativeConstruct() {
	Super::NativeConstruct();

	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &UGameHUDUserWidget::OnGameStateChanged);
		GS->OnCountdownUpdated.AddDynamic(this, &UGameHUDUserWidget::OnCountdownUpdated);
	}

	if (auto* PC = GetOwningPlayer()) {
		if (auto* PS = PC->GetPlayerState<AMyPlayerState>()) {
			PS->OnPlayerScoreChanged.AddDynamic(this, &UGameHUDUserWidget::OnPlayerScoreChanged);
		}
		if (auto* PP = Cast<APlayerPaperCharacter>(PC->GetPawn())) {
			PP->OnPlayerStatusChanged.AddDynamic(this, &UGameHUDUserWidget::OnPlayerStatusChanged);
		}
	}
}

void UGameHUDUserWidget::UpdateScore(int32 Score) {
	if (TB_Score)
	{
		TB_Score->SetText(FText::Format(NSLOCTEXT("UGameHUDUserWidget", "ScoreText", "Score: {0}"), FText::AsNumber(Score)));
	}
}

void UGameHUDUserWidget::HideScore(bool Toggle) {
	if (TB_Score) {
		if (Toggle) {
			TB_Score->SetVisibility(ESlateVisibility::Hidden);
		}
		else {
			TB_Score->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void UGameHUDUserWidget::UpdateCountdown(float Time) {
	if (TB_Countdown) {
		TB_Countdown->SetText(FText::Format(NSLOCTEXT("UGameHUDUserWidget", "Countdown", "Game Start in: {0}"), FText::AsNumber(Time)));
	}
}

void UGameHUDUserWidget::HideCountdown(bool Toggle) {
	if (TB_Countdown) {
		if (Toggle) {
			TB_Countdown->SetVisibility(ESlateVisibility::Hidden);
		}
		else {
			TB_Countdown->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void UGameHUDUserWidget::OnGameStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		break;
	case EMainGameState::Countdown:
		HideCountdown(false);
		break;
	case EMainGameState::Started:
		HideCountdown(true);
		break;
	case EMainGameState::GameOver:
		break;

	default:
		break;
	}
}

void UGameHUDUserWidget::OnPlayerStatusChanged(EPlayerStatus NewStatus) {
	switch (NewStatus) {
	case EPlayerStatus::Alive:
		break;
	case EPlayerStatus::Dead:
		break;
	default:
		break;
	}
}

void UGameHUDUserWidget::OnPlayerScoreChanged(int32 NewScore) {
	UpdateScore(NewScore);
}

void UGameHUDUserWidget::OnCountdownUpdated(float NewTime) {
	UpdateCountdown(NewTime);
}