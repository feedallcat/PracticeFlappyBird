// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyUserWidget.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	void UpdateTBScore(int32 Score);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> MainWidgetClass;

	UMyUserWidget* MyWidgetKub;
};
