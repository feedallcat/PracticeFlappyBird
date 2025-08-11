// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjectManager.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"

AWorldObjectManager::AWorldObjectManager() {
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWorldObjectManager::BeginPlay()
{
	Super::BeginPlay();

	TopTriggerBox->OnActorBeginOverlap.AddDynamic(this, &AWorldObjectManager::OnBoundariesOverlap);
	BottomTriggerBox->OnActorBeginOverlap.AddDynamic(this, &AWorldObjectManager::OnBoundariesOverlap);

	if (AMainGameStateBase* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		GS->OnGameStateChanged.AddDynamic(this, &AWorldObjectManager::OnGameStateChanged);
	}

	for (ATriggerBox* Destroyer : DestroyerList) {
		Destroyer->OnActorBeginOverlap.AddDynamic(this, &AWorldObjectManager::OnDestroyerOverlap);
	}
}

void AWorldObjectManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	for (AActor* Obstacle : ObstaclesPipeList) {
		FVector CurrentLocation = Obstacle->GetActorLocation();
		FVector NewLocation = FVector(CurrentLocation.X - CurrentLocation.X * ObstacleSpeed * DeltaTime, CurrentLocation.Y, CurrentLocation.Z);
		Obstacle->SetActorLocation(NewLocation);
	}
}


void AWorldObjectManager::OnBoundariesOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (APlayerPaperCharacter* Player = Cast<APlayerPaperCharacter>(OtherActor)) {
		Player->TouchedTriggerBox();
	}
}

void AWorldObjectManager::OnDestroyerOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (OtherActor->IsA(ObstacleBlueprint)) {
		DestroyObstacle(OtherActor);
		return;
	}
	if (APlayerPaperCharacter* P1 = Cast<APlayerPaperCharacter>(OtherActor)) {
		GetWorld()->DestroyActor(P1);
		return;
	}
	GetWorld()->DestroyActor(OtherActor);
}

void AWorldObjectManager::OnGameStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		SpawnObstacle();
		break;
	case EMainGameState::Playing:
		break;
	case EMainGameState::GameOver:
		break;
	default:
		break;
	}
}

void AWorldObjectManager::SpawnObstacle() {
	if (UWorld* World = GetWorld()) {
		if (ObstaclePipe) {
			if (ObstacleSpawnPointList.Num() > 0) {
				int32 RandomIndex = FMath::RandRange(0, ObstacleSpawnPointList.Num() - 1);
				ATargetPoint* RandomTargetPoint = ObstacleSpawnPointList[RandomIndex];
				FRotator SpawnRotation = GetActorRotation();
				AActor* obstacle = World->SpawnActor<AActor>(ObstaclePipe, RandomTargetPoint->GetActorLocation(), SpawnRotation);
				ObstaclesPipeList.Add(obstacle);
			}
		}
	}
}

void AWorldObjectManager::DestroyObstacle(AActor* Obstacle) {
	ObstaclesPipeList.Remove(Obstacle);
	GetWorld()->DestroyActor(Obstacle);
}

