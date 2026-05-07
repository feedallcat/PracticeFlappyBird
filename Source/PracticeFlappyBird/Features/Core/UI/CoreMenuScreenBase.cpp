// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMenuScreenBase.h"

TOptional<FUIInputConfig> UCoreMenuScreenBase::GetDesiredInputConfig() const {
	return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture, false);
}