// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FlappyBirdSaveGameData.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UFlappyBirdSaveGameData : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Save Data")
	int32 HighScore = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Save Data")
	FString PlayerName = TEXT("Player Name");
	
};
