// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EMainGameState : uint8
{
    None           UMETA(DisplayName = "None"),          // No game state set
    WaitingToStart UMETA(DisplayName = "Waiting To Start"), // Game loaded, waiting for first input
    Started        UMETA(DisplayName = "Stared"),        // Active gameplay
    GameOver       UMETA(DisplayName = "Game Over")       // Player died, game ended
};

UENUM(BlueprintType)
enum class EPlayerStatus : uint8
{
    None		UMETA(DisplayName = "None"),
    Alive		UMETA(DisplayName = "Alive"),
    Dead		UMETA(DisplayName = "Dead")
};