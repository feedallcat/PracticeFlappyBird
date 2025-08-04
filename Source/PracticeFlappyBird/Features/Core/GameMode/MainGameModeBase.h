// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "MainGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Game Mode")
	void RestartGame();

	UFUNCTION(BlueprintCallable, Category = "Game Mode")
	void HandlePlayerDie();

protected:
	void BeginPlay() override;

	void HandleCountdown();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Mode")
	float CountdownTime = 3.0f;

	FTimerHandle CountdownTimerHandle;

};
