// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManagerSubsystem.h"
#include "Blueprint/UserWidget.h"

void UUIManagerSubsystem::ShowScreen(TSubclassOf<UUserWidget> ScreenClass)
{
	if (!ScreenClass) return;

	// Remove old widget if exists
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PC = World->GetFirstPlayerController())
		{
			CurrentWidget = CreateWidget<UUserWidget>(PC, ScreenClass);
			if (CurrentWidget)
			{
				CurrentWidget->AddToViewport(0); // 0 = base layer
			}
		}
	}
}

void UUIManagerSubsystem::ClearScreen()
{
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}
}