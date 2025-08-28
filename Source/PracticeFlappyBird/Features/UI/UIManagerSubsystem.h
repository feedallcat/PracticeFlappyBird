// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UIManagerSubsystem.generated.h"

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ShowScreen(TSubclassOf<UUserWidget> ScreenClass);
	UFUNCTION(BlueprintCallable)
	void ClearScreen();

	UUserWidget* GetCurrentWidget() const { return CurrentWidget; };

private:
	UPROPERTY()
	UUserWidget* CurrentWidget;
};
