// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDUserWidget.h"
#include "Components/TextBlock.h"

void UGameHUDUserWidget::UpdateScore(int32 Score) {
	if(TB_Score)
	{
		TB_Score->SetText(FText::Format(NSLOCTEXT("UGameHUDUserWidget", "ScoreText", "Score: {0}"), FText::AsNumber(Score)));
	}
}