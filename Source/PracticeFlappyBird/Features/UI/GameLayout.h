// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PracticeFlappyBird/Features/Core/UI/CoreLayoutBase.h"
#include "GameLayout.generated.h"

class UCommonActivatableWidget;
/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UGameLayout : public UCoreLayoutBase
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(EditDefaultsOnly, Category = "Screens")
	TSubclassOf<UCommonActivatableWidget> GameHudScreenClass;

	UPROPERTY(EditDefaultsOnly, Category = "Screens")
	TSubclassOf<UCommonActivatableWidget> GameOverScreenClass;

	UPROPERTY(EditDefaultsOnly, Category = "Screens")
	TSubclassOf<UCommonActivatableWidget> PauseMenuScreenClass;

	UFUNCTION()
	void OnPlayerStatusChanged(EPlayerStatus NewStatus);

	UFUNCTION()
	void OnPlayStateChanged(EMainGameState NewState);
};
