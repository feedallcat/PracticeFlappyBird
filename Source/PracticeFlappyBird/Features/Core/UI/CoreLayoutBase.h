// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonActivatableWidget.h"
#include "CoreLayoutBase.generated.h"

class UCommonActivatableWidgetStack;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UCoreLayoutBase : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Layout")
	UCommonActivatableWidget* PushScreen(TSubclassOf<UCommonActivatableWidget> ScreenClass);

	UFUNCTION(BlueprintCallable, Category = "Layout")
	void PopCurrentScreen();

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetStack* MainStack;
};
