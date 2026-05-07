// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreButtonBase.h"
#include "CommonTextBlock.h"

void UCoreButtonBase::NativePreConstruct() {
	Super::NativePreConstruct();
	if (CTB_Text) {
		CTB_Text->SetText(ButtonText);
	}
}