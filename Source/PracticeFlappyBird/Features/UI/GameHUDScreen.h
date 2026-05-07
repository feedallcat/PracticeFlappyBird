// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PracticeFlappyBird/Features/Core/UI/CoreGameScreenBase.h"
#include "GameHUDScreen.generated.h"

class UCommonTextBlock;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UGameHUDScreen : public UCoreGameScreenBase
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* CTB_Score;

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* CTB_Countdown;

	void UpdateScore(int32 Score);

	void HideScore(bool Toggle);

	void UpdateCountdown(float Time);
	void HideCountdown(bool Toggle);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnGameStateChanged(EMainGameState NewState);

	UFUNCTION()
	void OnPlayerScoreChanged(int32 NewScore);

	UFUNCTION()
	void OnCountdownUpdated(float NewTime);

	UFUNCTION()
	void OnPlayerStatusChanged(EPlayerStatus NewStatus);
	
};
