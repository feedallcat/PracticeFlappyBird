// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "UIManagerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScreenChanged, UUserWidget*, NewWidget);

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="UI")
	FOnScreenChanged OnScreenOpened;

	UFUNCTION(BlueprintCallable)
	void ShowScreen(TSubclassOf<UUserWidget> ScreenClass);
	UFUNCTION(BlueprintCallable)
	void ClearScreen();

	UUserWidget* GetCurrentWidget() const { return CurrentWidget; };

private:
	UPROPERTY()
	UUserWidget* CurrentWidget;
};
