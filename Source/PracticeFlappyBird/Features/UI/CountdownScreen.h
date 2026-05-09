// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PracticeFlappyBird/Features/Core/UI/CoreMenuScreenBase.h"
#include "CountdownScreen.generated.h"

class UCommonTextBlock;
/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UCountdownScreen : public UCoreMenuScreenBase
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(meta = (BindWidget))
	UCommonTextBlock* CTB_Countdown;

	UFUNCTION()
	void OnCountdownUpdated(float Time);
};
