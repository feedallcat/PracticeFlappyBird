// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AMenuGameModeBase::BeginPlay() {
	Super::BeginPlay();

	if (MenuLayoutClass)
	{
		if (auto* PC = UGameplayStatics::GetPlayerController(this, 0)) {
			if (auto* MenuLayout = CreateWidget<UUserWidget>(PC, MenuLayoutClass))
			{
				MenuLayout->AddToViewport();
			}
		}
	}
}