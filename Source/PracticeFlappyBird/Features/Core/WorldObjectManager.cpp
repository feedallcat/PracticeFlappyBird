// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjectManager.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"

// Called when the game starts or when spawned
void AWorldObjectManager::BeginPlay()
{
	Super::BeginPlay();

	if (!TopTriggerBox || !BottomTriggerBox) {
		UE_LOG(LogTemp, Error, TEXT("Trigger boxes not set in WorldObjectManager! Please assign them in the editor."));
		return;
	}

	TopTriggerBox->OnActorBeginOverlap.AddDynamic(this, &AWorldObjectManager::HandleTriggerBoxOverlap);
	BottomTriggerBox->OnActorBeginOverlap.AddDynamic(this, &AWorldObjectManager::HandleTriggerBoxOverlap);
}


void AWorldObjectManager::HandleTriggerBoxOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (APlayerPaperCharacter* Player = Cast<APlayerPaperCharacter>(OtherActor)) {
		Player->TouchedTriggerBox();
	}
}

