// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjectManager.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWorldObjectManager::AWorldObjectManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

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

	CurrentGameMode = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void AWorldObjectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWorldObjectManager::HandleTriggerBoxOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (CurrentGameMode) {
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC) {
			APlayerPaperCharacter* Player = Cast<APlayerPaperCharacter>(PC->GetPawn());
			CurrentGameMode->HandlePlayerDie(Player);
		}
	}
}

