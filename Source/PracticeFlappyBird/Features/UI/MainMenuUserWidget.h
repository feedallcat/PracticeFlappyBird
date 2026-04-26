// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuUserWidget.generated.h"

class UButton;

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Play;

	UPROPERTY(meta = (BindWidget))
	UButton* BTN_Quit;

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
