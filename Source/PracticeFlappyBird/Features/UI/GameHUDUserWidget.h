// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDUserWidget.generated.h"

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UGameHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TB_Score;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TB_Countdown;

	void UpdateScore(int32 Score);

	void HideScore(bool Toggle);

	void UpdateCountdown(float Time);
	void HideCountdown(bool Toggle);

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnGameStateChanged(EMainGameState NewState);

	UFUNCTION()
	void OnPlayerScoreChanged(int32 NewScore);

	UFUNCTION()
	void OnCountdownUpdated(float NewTime);

	UFUNCTION()
	void OnPlayerStatusChanged(EPlayerStatus NewStatus);
};
