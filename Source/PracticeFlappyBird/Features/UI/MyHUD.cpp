// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"

void AMyHUD::BeginPlay() {
	Super::BeginPlay();
	if (MainWidgetClass) {
		UUserWidget* MainWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);
		if (MainWidget) {
			MainWidget->AddToViewport();
		}
	}
}