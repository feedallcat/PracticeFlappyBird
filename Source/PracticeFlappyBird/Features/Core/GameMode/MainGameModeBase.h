// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameModeBase.generated.h"

class UMyGameInstance;
class UGameHUDUserWidget;

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	void StartGame();

	void RestartGame();

protected:

	UFUNCTION()
	void HandleScreenOpened(UUserWidget* NewWidget);

	UPROPERTY(Transient)
	UMyGameInstance* MyGameInstance;

	UPROPERTY(Transient)
	UGameHUDUserWidget* MyGameHUDUserWidget;

	void BeginPlay() override;

	void HandleCountdown();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Mode")
	float CountdownTime = 3.0f;

	FTimerHandle CountdownTimerHandle;

	UFUNCTION()
	void OnPlayerStatusChanged(EPlayerStatus NewStatus);

	UFUNCTION()
	void OnPlayStateChanged(EMainGameState NewState);
};
