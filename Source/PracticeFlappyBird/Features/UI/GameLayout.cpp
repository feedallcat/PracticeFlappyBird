// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLayout.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"

void UGameLayout::NativeConstruct() {
	Super::NativeConstruct();
	if (AMainGameStateBase* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &UGameLayout::OnPlayStateChanged);
	}
	if (APlayerPaperCharacter* P1 = APlayerPaperCharacter::GetCurrentPlayer(GetWorld())) {
		P1->OnPlayerStatusChanged.AddDynamic(this, &UGameLayout::OnPlayerStatusChanged);
	}
}

void UGameLayout::NativeDestruct() {
	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.RemoveDynamic(this, &UGameLayout::OnPlayStateChanged);
	}
	if (auto* PC = GetOwningPlayer()) {
		if (auto* PP = Cast<APlayerPaperCharacter>(PC->GetPawn())) {
			PP->OnPlayerStatusChanged.RemoveDynamic(this, &UGameLayout::OnPlayerStatusChanged);
		}
	}
	Super::NativeDestruct();
}

void UGameLayout::OnPlayStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		break;
	case EMainGameState::GameOver:
		if (GameOverScreenClass) {
			PushScreen(GameOverScreenClass);
		}
		break;
	case EMainGameState::Started:
		break;
	default:
		break;
	}
}

void UGameLayout::OnPlayerStatusChanged(EPlayerStatus NewStatus) {
	switch (NewStatus) {
	case EPlayerStatus::Alive:
		break;
	case EPlayerStatus::Dead:
		break;
	default:
		break;
	}

}