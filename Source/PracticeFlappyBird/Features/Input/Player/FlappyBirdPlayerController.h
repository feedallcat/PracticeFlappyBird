// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FlappyBirdPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

class UEnhancedInputLocalPlayerSubsystem;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AFlappyBirdPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void AddInputContext(const UInputMappingContext* Context, int32 Priority = 0);
	void RemoveInputContext(const UInputMappingContext* Context);
	void RequestPause();

protected:
	 void BeginPlay() override;

	 void SetupInputComponent() override;

	 UFUNCTION()
	 void OnPlayStateChanged(EMainGameState NewState);

private:
	UPROPERTY(Transient)
	UEnhancedInputLocalPlayerSubsystem* Subsystem;

	UPROPERTY(EditDefaultsOnly, Category = "Flappy Bird Input")
	UInputMappingContext* PlayingIMC;

	UPROPERTY(EditDefaultsOnly, Category = "Flappy Bird Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Flappy Bird Input")
	UInputAction* PauseAction;

	void RequestJump();
};
