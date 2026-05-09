// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PracticeFlappyBird/Features/Core/UI/CoreMenuScreenBase.h"
#include "GameOverScreen.generated.h"

class UCommonButtonBase;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UGameOverScreen : public UCoreMenuScreenBase
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(meta = (BindWidget))
	UCommonButtonBase* BTN_Restart;

	UFUNCTION()
	void OnRestartClicked();
	
};
