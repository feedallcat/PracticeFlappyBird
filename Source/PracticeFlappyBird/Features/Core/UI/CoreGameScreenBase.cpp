// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameScreenBase.h"

TOptional< FUIInputConfig> UCoreGameScreenBase::GetDesiredInputConfig() const {
	return FUIInputConfig(ECommonInputMode::Game, EMouseCaptureMode::CapturePermanently, true);
}