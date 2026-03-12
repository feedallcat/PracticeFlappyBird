// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPaperCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "Components/CapsuleComponent.h"
#include "PracticeFlappyBird/Features/Core/PlayerState/MyPlayerState.h"
#include "PracticeFlappyBird/Features/Core/MyGameInstance.h"
#include "PracticeFlappyBird/Features/UI/GameHUDUserWidget.h"
#include "PracticeFlappyBird/Features/UI/UIManagerSubsystem.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "PracticeFlappyBird/Features/Core/GameDefinitions.h"

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
	case EMainGameState::Started:
		if (UGameHUDUserWidget* GameHud = GetGameHud()) {
			GameHud->HideScore(false);
			if (AMyPlayerState* PS = GetMyPlayerState()) {
				PS->PlayerScore = 0;
				GameHud->HideScore(0);
			}
		}
		
		Unfreeze();
		break;
	case EMainGameState::GameOver:
		//Freeze();
		break;
	default:
		break;
	}
}

class AMyPlayerState* APlayerPaperCharacter::GetMyPlayerState()
{
	if (!MyPS)
	{
		MyPS = GetPlayerState<AMyPlayerState>();
	}
	return MyPS;
}

UGameHUDUserWidget* APlayerPaperCharacter::GetGameHud() {
	if (auto* MyGI = GetGameInstance<UMyGameInstance>()) {
		if (auto* MyUI = MyGI->GetUIManager()) {
			if (auto* HUD = Cast<UGameHUDUserWidget>(MyUI->GetCurrentWidget())) {
				return HUD;
			}
		}
	}
	return nullptr;
}

void APlayerPaperCharacter::AddScore_Implementation(int32 Score) {
	if (AMyPlayerState* PS = GetMyPlayerState()) {
		PS->PlayerScore += Score;
		if (UGameHUDUserWidget* GameHud = GetGameHud()) {
			GameHud->UpdateScore(PS->PlayerScore);
		}
	}
}

void APlayerPaperCharacter::Die_Implementation() {
	OnPlayerStatusChanged.Broadcast(EPlayerStatus::Dead);
}