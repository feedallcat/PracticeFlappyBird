// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Core/MainGameState.h"
#include "PracticeFlappyBird/Features/Input/Player/FlappyBirdPlayerController.h"

void AMainGameModeBase::BeginPlay() {
	Super::BeginPlay();
	if (AMainGameStateBase* GS = GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &AMainGameModeBase::OnPlayStateChanged);
		GS->SetGameState(EMainGameState::WaitingToStart);
	}
	if (APlayerPaperCharacter* P1 = APlayerPaperCharacter::GetCurrentPlayer(GetWorld())) {
		P1->OnPlayerDied.AddDynamic(this, &AMainGameModeBase::OnPlayerDied);
	}
}

void AMainGameModeBase::StartGame() {
	if (AMainGameStateBase* GS = GetGameState<AMainGameStateBase>()) {
		GS->SetGameState(EMainGameState::None);
	}
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AMainGameModeBase::HandleCountdown, 1.0f, true);
}

void AMainGameModeBase::RestartGame() {
	if (APlayerPaperCharacter* P1 = APlayerPaperCharacter::GetCurrentPlayer(GetWorld())) {
		if (AFlappyBirdPlayerController* PC = Cast<AFlappyBirdPlayerController>(P1->GetController())) {
			UE_LOG(LogTemp, Warning, TEXT("Restarting game for player!!"));
			RestartPlayer(PC);
		}
	}
}

void AMainGameModeBase::HandleCountdown() {
	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Game started!"));
		if (AMainGameStateBase* GS = GetGameState<AMainGameStateBase>()) {
			GS->SetGameState(EMainGameState::Playing);
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Game start in : %f"), CountdownTime);
		CountdownTime -= 1.0f;
	}
}

void AMainGameModeBase::OnPlayStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		break;
	case EMainGameState::GameOver:
		break;
	case EMainGameState::Playing:
		break;
	default:
		break;
	}
}

void AMainGameModeBase::OnPlayerDied() {
	if (AMainGameStateBase* GS = GetGameState<AMainGameStateBase>()) {
		GS->SetGameState(EMainGameState::GameOver);
	}
}