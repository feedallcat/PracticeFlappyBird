// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldObjectManager.generated.h"

class ATriggerBox;
class ATargetPoint;

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

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Obstacle")
	TArray<UClass*> ObstaclePipeClassList;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Obstacle")
	TArray<ATargetPoint*> ObstacleSpawnPointList;

private:
	UPROPERTY(Transient)
	TArray<AActor*> ObstaclesPipeList;

	UFUNCTION()
	void OnGameStateChanged(EMainGameState NewState);

	UFUNCTION()
	void OnPlayerStatusChanged(EPlayerStatus NewStatus);

	UFUNCTION()
	void DestroyObstacle(AActor* Obstacle);
	void DestroyAllObstacles();

	UPROPERTY(EditDefaultsOnly, Category = "Obstacle")
	UClass* ObstacleBlueprint;

	UPROPERTY(EditInstanceOnly, Category="Obstacle")
	float ObstacleSpeed = 100.0f;

	float ElapsedTime = 0.0f;
	void MoveObstacle(float MoveSpeed);
	void SpawnObstacle(int32 Second, float DeltaTime);

};
