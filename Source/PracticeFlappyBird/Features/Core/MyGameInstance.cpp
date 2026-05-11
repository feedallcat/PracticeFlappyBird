// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "PracticeFlappyBird/Features/Core/Save/FlappyBirdSaveGameData.h"

void UMyGameInstance::Init()
{
	Super::Init();
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0)) {
		USaveGame* LoadedSaveGame = UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0);
		CachedSaveData = Cast<UFlappyBirdSaveGameData>(LoadedSaveGame);
	}
	else {
		USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(UFlappyBirdSaveGameData::StaticClass());
		CachedSaveData = Cast<UFlappyBirdSaveGameData>(NewSaveGame);
	}
}

void UMyGameInstance::SaveHighScore(int32 NewHighScore, FString PlayerName) {
	if (CachedSaveData && NewHighScore > CachedSaveData->HighScore) {
		CachedSaveData->HighScore = NewHighScore;
		CachedSaveData->PlayerName = PlayerName;

		UGameplayStatics::SaveGameToSlot(CachedSaveData, SaveSlotName, 0);
		UE_LOG(LogTemp, Warning, TEXT("New High Score Saved: %d"), NewHighScore);
	}
}