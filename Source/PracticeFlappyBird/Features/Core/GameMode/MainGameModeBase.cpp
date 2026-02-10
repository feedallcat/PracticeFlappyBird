// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Input/Player/FlappyBirdPlayerController.h"
#include "PracticeFlappyBird/Features/UI/GameHUDUserWidget.h"
#include "PracticeFlappyBird/Features/UI/UIManagerSubsystem.h"


void AMainGameModeBase::BeginPlay() {
	Super::BeginPlay();

	if (auto* MyGI = GetGameInstance<UMyGameInstance>()) {
		if (auto* MyUI = MyGI->GetUIManager()) {
			MyGameInstance = MyGI;
			MyUI->OnScreenOpened.AddDynamic(this, &AMainGameModeBase::HandleScreenOpened);
		}
	}

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
			GetWorld()->DestroyActor(P1);
			RestartPlayer(PC);
			if (APlayerPaperCharacter* P2 = APlayerPaperCharacter::GetCurrentPlayer(GetWorld())) {
				P2->OnPlayerDied.AddDynamic(this, &AMainGameModeBase::OnPlayerDied);
			}
			if (AMainGameStateBase* GS = GetGameState<AMainGameStateBase>()) {
				GS->SetGameState(EMainGameState::WaitingToStart);
			}
		}
	}
}

void AMainGameModeBase::HandleCountdown() {

	MyGameHUDUserWidget->HideCountdown(false);
	MyGameHUDUserWidget->UpdateCountdown(CountdownTime);

	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Game started!"));
		if (AMainGameStateBase* GS = GetGameState<AMainGameStateBase>()) {
			GS->SetGameState(EMainGameState::Playing);
		}
		MyGameHUDUserWidget->HideCountdown(true);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Game start in : %f"), CountdownTime);
		CountdownTime -= 1.0f;
	}
}

void AMainGameModeBase::HandleScreenOpened(UUserWidget* NewWidget) {
	if (auto* HUD = Cast<UGameHUDUserWidget>(NewWidget)) {
		MyGameHUDUserWidget = HUD;
	}
}

void AMainGameModeBase::OnPlayStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		CountdownTime = 3.0f;
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