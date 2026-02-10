// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDUserWidget.h"
#include "Components/TextBlock.h"

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

void UGameHUDUserWidget::UpdateCountdown(int32 Time) {
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