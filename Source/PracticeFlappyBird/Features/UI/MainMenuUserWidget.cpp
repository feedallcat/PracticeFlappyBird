// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Button.h"

void UMainMenuUserWidget::NativeConstruct() {
	Super::NativeConstruct();
	if (BTN_Play) {
		BTN_Play->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnPlayBtnClicked);
	}
	if (BTN_Quit) {
		BTN_Quit->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnQuitBtnClicked);
	}
}

void UMainMenuUserWidget::NativeDestruct() {
	if (BTN_Play) {
		BTN_Play->OnClicked.RemoveDynamic(this, &UMainMenuUserWidget::OnPlayBtnClicked);
	}
	if (BTN_Quit) {
		BTN_Quit->OnClicked.RemoveDynamic(this, &UMainMenuUserWidget::OnQuitBtnClicked);
	}
	Super::NativeDestruct();
}

void UMainMenuUserWidget::OnPlayBtnClicked() {
	if (!GameLevel.IsNull()) {
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, GameLevel);
	}
}

void UMainMenuUserWidget::OnQuitBtnClicked() {
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}