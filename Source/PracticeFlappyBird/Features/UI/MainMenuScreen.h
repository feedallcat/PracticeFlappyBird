// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PracticeFlappyBird/Features/Core/UI/CoreMenuScreenBase.h"
#include "MainMenuScreen.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UMainMenuScreen : public UCoreMenuScreenBase
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UCommonButtonBase* BTN_Play;

	UPROPERTY(meta = (BindWidget))
	UCommonButtonBase* BTN_Quit;

	UPROPERTY(meta = (BindWidget))
	UCommonTextBlock* CTB_Highscore;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main Menu")
	TSoftObjectPtr<UWorld> GameLevel;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	UFUNCTION()
	void OnPlayBtnClicked();
	UFUNCTION()
	void OnQuitBtnClicked();
	
};
