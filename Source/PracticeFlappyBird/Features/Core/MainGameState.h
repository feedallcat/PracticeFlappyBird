// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainGameState.generated.h"

UENUM(BlueprintType)
enum class EMainGameState: uint8
{
	None           UMETA(DisplayName = "None"),          // No game state set
    WaitingToStart UMETA(DisplayName = "Waiting To Start"), // Game loaded, waiting for first input
    Playing        UMETA(DisplayName = "Playing"),        // Active gameplay
    GameOver       UMETA(DisplayName = "Game Over")       // Player died, game ended
};