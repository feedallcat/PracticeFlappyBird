// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PracticeFlappyBird/Features/Core/Save/FlappyBirdSaveGameData.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UPROPERTY(BlueprintReadWrite, Category = "Save Data")
	UFlappyBirdSaveGameData* CachedSaveData;
	

	UFUNCTION(BlueprintCallable, Category = "Save Data")
	void SaveHighScore(int32 NewHighScore, FString PlayerName);

private:
	FString SaveSlotName = TEXT("FlappyBirdSaveSlot");;
};
