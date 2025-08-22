// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/TextBlock.h"

void UMyUserWidget::UpdateTBScore(int32 Score) {
	if(TB_Score)
	{
		TB_Score->SetText(FText::Format(NSLOCTEXT("UMyUserWidget", "ScoreText", "Score: {0}"), FText::AsNumber(Score)));
	}
}