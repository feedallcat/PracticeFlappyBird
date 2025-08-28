// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "PracticeFlappyBird/Features/UI/UIManagerSubsystem.h"

UUIManagerSubsystem* UMyGameInstance::GetUIManager() const
{
    return GetSubsystem<UUIManagerSubsystem>();
}