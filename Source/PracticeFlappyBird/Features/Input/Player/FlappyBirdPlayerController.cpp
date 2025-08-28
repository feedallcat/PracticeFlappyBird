// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBirdPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "PracticeFlappyBird/Features/Core/MainGameState.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "PracticeFlappyBird/Features/Core/MyGameInstance.h"
#include "PracticeFlappyBird/Features/UI/UIManagerSubsystem.h"

void AFlappyBirdPlayerController::BeginPlay() {
	Super::BeginPlay();
	if (ULocalPlayer* LP = GetLocalPlayer()) {
		Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	}

	if (APlayerPaperCharacter* p1 = APlayerPaperCharacter::GetCurrentPlayer(this)) {
		if (AFlappyBirdPlayerController* PC = Cast< AFlappyBirdPlayerController>(p1->GetController())) {
			if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PC->InputComponent)) {
				if (StartGameAction) {
					EIC->BindAction(StartGameAction, ETriggerEvent::Started, this, &AFlappyBirdPlayerController::RequestStartGame);
				}
				if (RestartGameAction) {
					EIC->BindAction(RestartGameAction, ETriggerEvent::Started, this, &AFlappyBirdPlayerController::RequestRestartGame);
				}
			}
		}
	}

	if (AMainGameStateBase* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &AFlappyBirdPlayerController::OnPlayStateChanged);
		OnPlayStateChanged(GS->CurrentGameState);
	}

	if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
	{
		GI->GetUIManager()->ShowScreen(GI->InGameHUDWidgetClass);
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
	}
}

void AFlappyBirdPlayerController::RequestJump() {
	if (APlayerPaperCharacter* P1 = APlayerPaperCharacter::GetCurrentPlayer(this)) {
		P1->RequestJump();
	}
	
}

void AFlappyBirdPlayerController::OnPlayStateChanged(EMainGameState NewState) {
	Subsystem->ClearAllMappings();
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		Subsystem->AddMappingContext(StartGameIMC, 0);
		break;
	case EMainGameState::GameOver:
		Subsystem->AddMappingContext(GameOverIMC, 0);
		break;
	case EMainGameState::Playing:
		Subsystem->AddMappingContext(PlayingIMC, 0);
		break;
	default:
		break;
	}
}

void AFlappyBirdPlayerController::RequestStartGame() {
	if (AMainGameModeBase* GM = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode())) {
		GM->StartGame();
	}
}

void AFlappyBirdPlayerController::RequestRestartGame() {
	if (AMainGameModeBase* GM = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode())) {
		GM->RestartGame();
	}
}