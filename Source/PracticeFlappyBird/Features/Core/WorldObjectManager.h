// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "Engine/TargetPoint.h"
#include "WorldObjectManager.generated.h"

UCLASS()
class PRACTICEFLAPPYBIRD_API AWorldObjectManager : public AActor
{
	GENERATED_BODY()

public:
	AWorldObjectManager();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Boundaries")
	ATriggerBox* TopTriggerBox;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Boundaries")
	ATriggerBox* BottomTriggerBox;

	UFUNCTION()
	void OnBoundariesOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Obstacle")
	TArray<UClass*> ObstaclePipeClassList;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Obstacle")
	TArray<ATargetPoint*> ObstacleSpawnPointList;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Destoyer")
	TArray<ATriggerBox*> DestroyerList;

private:
	TArray<AActor*> ObstaclesPipeList;

	UFUNCTION()
	void OnGameStateChanged(EMainGameState NewState);

	UFUNCTION()
	void OnDestroyerOverlap(AActor* OverlappedActor, AActor* OtherActor);

	void DestroyObstacle(AActor* Obstacle);
	UPROPERTY(EditDefaultsOnly, Category = "Obstacle")
	UClass* ObstacleBlueprint;

	UPROPERTY(EditInstanceOnly, Category="Obstacle")
	float ObstacleSpeed = 100.0f;

	float ElapsedTime = 0.0f;
	void MoveObstacle(float MoveSpeed);
	void SpawnObstacle(int32 Second, float DeltaTime);

};
