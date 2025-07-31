// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPaperCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerPaperCharacter::APlayerPaperCharacter() {

}

void APlayerPaperCharacter::BeginPlay() {
	Super::BeginPlay();
	if (APlayerController* PC = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer())) {
			if (ImcDefault) {
				Subsystem->AddMappingContext(ImcDefault, 0);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("ImcDefault is not set in APlayerPaperCharacter!"));
			}
		}
	}

	GetSprite()->SetLooping(false);
	JumpMaxCount = 999;
	JumpCurrentCount = 0;
}

void APlayerPaperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Log, TEXT("Start Setup Player Input Component"));
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		if (IaJump) {
			EnhancedInputComponent->BindAction(IaJump, ETriggerEvent::Triggered, this, &APlayerPaperCharacter::OnJumpInput);
			UE_LOG(LogTemp, Log, TEXT("Done Add Event "));
		}
	}
}

void APlayerPaperCharacter::OnJumpInput(const FInputActionValue& Value) {
	UE_LOG(LogTemp, Log, TEXT("Jump!!"));
	Jump();
	JumpCurrentCount = 0;
	GetSprite()->SetFlipbook(FbJumpUp);
	GetSprite()->SetPlaybackPosition(0.0f, false);
	GetSprite()->Play();
}