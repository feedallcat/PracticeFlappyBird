// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPaperCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Core/MainGameState.h"

void APlayerPaperCharacter::BeginPlay() {
	Super::BeginPlay();

	GetSprite()->SetLooping(false);
	JumpMaxCount = 999;
	JumpCurrentCount = 0;


	if (AMainGameStateBase* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &APlayerPaperCharacter::OnGameStateChanged);
	}

	Freeze();
}

void APlayerPaperCharacter::RequestJump() {
	Jump();
	JumpCurrentCount = 0;
	GetSprite()->SetFlipbook(FbJumpUp);
	GetSprite()->SetPlaybackPosition(0.0f, false);
	GetSprite()->Play();
}

void APlayerPaperCharacter::TouchedTriggerBox() const {
	OnPlayerDied.Broadcast();
}

void APlayerPaperCharacter::Freeze() {
	if (APlayerController* PC = Cast<APlayerController>(GetController())) {
		DisableInput(PC);
	}
	if (UCharacterMovementComponent* CMC = GetCharacterMovement()) {
		CMC->StopMovementImmediately();
	}
	CustomTimeDilation = 0.0f;
}

void APlayerPaperCharacter::Unfreeze() {
	if (APlayerController* PC = Cast<APlayerController>(GetController())) {
		EnableInput(PC);
	}

	CustomTimeDilation = 1.0f;
}

APlayerPaperCharacter* APlayerPaperCharacter::GetCurrentPlayer(const UObject* WorldContextObject) {
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (PC) {
		APlayerPaperCharacter* Player = Cast<APlayerPaperCharacter>(PC->GetPawn());
		return Player;
	}
	return nullptr;
}

void APlayerPaperCharacter::OnGameStateChanged(EMainGameState NewGameState) {
	switch (NewGameState) {
	case EMainGameState::WaitingToStart:
		Freeze();
		break;
	case EMainGameState::Playing:
		Unfreeze();
		break;
	case EMainGameState::GameOver:
		//Freeze();
		break;
	default:
		break;
	}
}