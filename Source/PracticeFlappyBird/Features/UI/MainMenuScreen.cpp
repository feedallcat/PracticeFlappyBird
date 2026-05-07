// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuScreen.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CommonButtonBase.h"

void UMainMenuScreen::NativeConstruct() {
	Super::NativeConstruct();
	if (BTN_Play) {
		BTN_Play->OnClicked().AddUObject(this, &UMainMenuScreen::OnPlayBtnClicked);
	}
	if (BTN_Quit) {
		BTN_Quit->OnClicked().AddUObject(this, &UMainMenuScreen::OnQuitBtnClicked);
	}
}

void UMainMenuScreen::NativeDestruct() {
	if (BTN_Play) {
		BTN_Play->OnClicked().RemoveAll(this);
	}
	if (BTN_Quit) {
		BTN_Quit->OnClicked().RemoveAll(this);
	}
	Super::NativeDestruct();
}

void UMainMenuScreen::OnPlayBtnClicked() {
	if (!GameLevel.IsNull()) {
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, GameLevel);
	}
}

void UMainMenuScreen::OnQuitBtnClicked() {
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
