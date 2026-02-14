// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjectManager.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "PracticeFlappyBird/Features/Player/PlayerPaperCharacter.h"
#include "PracticeFlappyBird/Features/Core/MainGameStateBase.h"
#include "Engine/TargetPoint.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"

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

	for (int32 i = 0; i < DestroyerList.Num(); i++) {
		ATriggerBox* DestroyerTriggerBox = DestroyerList[i];
		DestroyerTriggerBox->OnActorBeginOverlap.AddDynamic(this, &AWorldObjectManager::OnDestroyerOverlap);
	}
}

void AWorldObjectManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (AMainGameStateBase* GS = GetWorld()->GetGameState<AMainGameStateBase>()) {
		EMainGameState State = GS->CurrentGameState;

		switch (State) {
		case EMainGameState::WaitingToStart:
			break;
		case EMainGameState::Started:
			SpawnObstacle(2.0f, DeltaTime);
			MoveObstacle(ObstacleSpeed * DeltaTime);
			break;
		case EMainGameState::GameOver:
			break;
		default:
			break;
		}
	}
}

void AWorldObjectManager::MoveObstacle(float MoveSpeed) {
	for (int32 i = 0; i < ObstaclesPipeList.Num(); i++) {
		AActor* Obstacle = ObstaclesPipeList[i];
		FVector CurrentLocation = Obstacle->GetActorLocation();
		FVector NewLocation = FVector(CurrentLocation.X - MoveSpeed, CurrentLocation.Y, CurrentLocation.Z);
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
		P1->KilledPlayer();
		return;
	}
	GetWorld()->DestroyActor(OtherActor);
}

void AWorldObjectManager::OnGameStateChanged(EMainGameState NewState) {
	switch (NewState) {
	case EMainGameState::WaitingToStart:
		break;
	case EMainGameState::Started:
		break;
	case EMainGameState::GameOver:
		break;
	default:
		break;
	}
}

void AWorldObjectManager::SpawnObstacle(int32 Second, float DeltaTime) {
	ElapsedTime += DeltaTime;
	if (ElapsedTime > Second) {
		ElapsedTime = 0.0f;

		if (UWorld* World = GetWorld()) {
			int32 RandomObstaclePipeClassIndex = FMath::RandRange(0, ObstaclePipeClassList.Num() - 1);
			UClass* ObstaclePipeClass = ObstaclePipeClassList[RandomObstaclePipeClassIndex];
			if (ObstaclePipeClass) {
				if (ObstacleSpawnPointList.Num() > 0) {
					int32 RandomSpawnIndex = FMath::RandRange(0, ObstacleSpawnPointList.Num() - 1);
					ATargetPoint* RandomTargetPoint = ObstacleSpawnPointList[RandomSpawnIndex];
					FRotator SpawnRotation = GetActorRotation();
					AActor* Obstacle = World->SpawnActor<AActor>(ObstaclePipeClass, RandomTargetPoint->GetActorLocation(), SpawnRotation);
					ObstaclesPipeList.Add(Obstacle);
				}
			}
		}
	}
}

void AWorldObjectManager::DestroyObstacle(AActor* Obstacle) {
	ObstaclesPipeList.Remove(Obstacle);
	GetWorld()->DestroyActor(Obstacle);
}

