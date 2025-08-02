// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"

void AMainGameModeBase::BeginPlay() {
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AMainGameModeBase::HandleCountdown, 1.0f, true);
}

void AMainGameModeBase::HandleCountdown() {
	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Game started!"));	
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Game start in : %f"), CountdownTime);
		CountdownTime -= 1.0f;
	}
}

void AMainGameModeBase::HandlePlayerDie(APlayerPaperCharacter* Player) {
	UE_LOG(LogTemp, Warning, TEXT("Player died"))
}