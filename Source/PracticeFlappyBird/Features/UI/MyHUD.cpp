// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MyUserWidget.h"

void AMyHUD::BeginPlay() {
	Super::BeginPlay();
	if (MainWidgetClass) {
		UMyUserWidget* MainWidget = CreateWidget<UMyUserWidget>(GetWorld(), MainWidgetClass);
		if (MainWidget) {
			MainWidget->AddToViewport();
			MyWidgetKub = MainWidget;
		}
	}
}

void AMyHUD::UpdateTBScore(int32 Score) {
	if (MyWidgetKub) {
		MyWidgetKub->UpdateTBScore(Score);
	}
}