// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameModeBase.h"
#include "PracticeFlappyBird/Features/UI/UIManagerSubsystem.h"
#include "PracticeFlappyBird/Features/Core/MyGameInstance.h"

void AMenuGameModeBase::BeginPlay() {
	Super::BeginPlay();

	if (auto* GI = GetGameInstance<UMyGameInstance>()) {
		GI->GetUIManager()->ShowScreen(GI->MainMenuWidgetClass);
	}
}