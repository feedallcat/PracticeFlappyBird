// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreLayoutBase.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "CommonActivatableWidget.h"

UCommonActivatableWidget* UCoreLayoutBase::PushScreen(TSubclassOf<UCommonActivatableWidget> ScreenClass)
{
	if (MainStack && ScreenClass)
	{
		return MainStack->AddWidget(ScreenClass);
	}
	return nullptr;
}

void UCoreLayoutBase::PopCurrentScreen() {
	if (MainStack) {
		if (auto* TopWidget = MainStack->GetActiveWidget()) {
			TopWidget->DeactivateWidget();
		}
	}
}