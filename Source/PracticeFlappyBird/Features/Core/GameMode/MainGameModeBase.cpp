// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"

void AMainGameModeBase::BeginPlay() {
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AMainGameModeBase::HandleCountdown, 1.0f, true);
	if (APlayerPaperCharacter* Player = APlayerPaperCharacter::GetCurrentPlayer(this)) {
		Player->Freeze();
	}
}

void AMainGameModeBase::RestartGame() {

}

void AMainGameModeBase::HandleCountdown() {
	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Game started!"));
		if (APlayerPaperCharacter* Player = APlayerPaperCharacter::GetCurrentPlayer(this)) {
			Player->Unfreeze();
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Game start in : %f"), CountdownTime);
		CountdownTime -= 1.0f;
	}
}

void AMainGameModeBase::HandlePlayerDie() {
	if (APlayerPaperCharacter* Player = APlayerPaperCharacter::GetCurrentPlayer(this)) {
		Player->Freeze();
	}
}