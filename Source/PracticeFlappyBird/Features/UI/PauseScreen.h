// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PracticeFlappyBird/Features/Core/UI/CoreMenuScreenBase.h"
#include "PauseScreen.generated.h"

class UCommonButtonBase;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UPauseScreen : public UCoreMenuScreenBase
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UCommonButtonBase* BTN_Resume;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual bool NativeOnHandleBackAction() override;

private:
	UFUNCTION()
	void OnResumeBtnClicked();
	
};
