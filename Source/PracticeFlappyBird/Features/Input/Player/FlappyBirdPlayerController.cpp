// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBirdPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "Kismet/GameplayStatics.h"


void AFlappyBirdPlayerController::BeginPlay() {
	Super::BeginPlay();
	if (ULocalPlayer* LP = GetLocalPlayer()) {
		Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	}

	if (AMainGameStateBase* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &AFlappyBirdPlayerController::OnPlayStateChanged);
		OnPlayStateChanged(GS->CurrentGameState);
	}
}

void AFlappyBirdPlayerController::AddInputContext(const UInputMappingContext* Context, int32 Priority) {
	if (Subsystem) {
		Subsystem->AddMappingContext(Context, Priority);
	}
}

void AFlappyBirdPlayerController::RemoveInputContext(const UInputMappingContext* Context) {
	if (Subsystem) {
		Subsystem->RemoveMappingContext(Context);
	}
}

void AFlappyBirdPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent)) {
		if (JumpAction) {
			EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &AFlappyBirdPlayerController::RequestJump);
		}
		if (PauseAction) {
			EIC->BindAction(PauseAction, ETriggerEvent::Started, this, &AFlappyBirdPlayerController::RequestPause);
		}
	}
}

void AFlappyBirdPlayerController::RequestJump() {
	if (APlayerPaperCharacter* P1 = APlayerPaperCharacter::GetCurrentPlayer(this)) {
		P1->RequestJump();
	}

}

void AFlappyBirdPlayerController::RequestPause() {
	UE_LOG(LogTemp, Warning, TEXT("Toggle Pause!!!"));
	if (auto* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		if (UGameplayStatics::IsGamePaused(this)) {
			GS->SetGameState(EMainGameState::Started);
			UGameplayStatics::SetGamePaused(this, false);
		}
		else {
			GS->SetGameState(EMainGameState::Pause);
			UGameplayStatics::SetGamePaused(this, true);
		}
	}

}

void AFlappyBirdPlayerController::OnPlayStateChanged(EMainGameState NewState) {
	Subsystem->ClearAllMappings();
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		break;
	case EMainGameState::GameOver:
		break;
	case EMainGameState::Started:
	case EMainGameState::Pause:
		Subsystem->AddMappingContext(PlayingIMC, 0);
		break;
	default:
		break;
	}
}