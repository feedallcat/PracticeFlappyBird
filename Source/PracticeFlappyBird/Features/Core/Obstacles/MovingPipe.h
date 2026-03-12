// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PracticeFlappyBird/Features/Core/Interface/OffscreenDespawn.h"
#include "MovingPipe.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class PRACTICEFLAPPYBIRD_API AMovingPipe : public AActor, public IOffscreenDespawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPipe();

	virtual void Despawn_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Obstacle")
	UStaticMeshComponent* UpperPipeRef;

	UPROPERTY(BlueprintReadWrite, Category = "Obstacle")
	UStaticMeshComponent* LowerPipeRef;

	UPROPERTY(BlueprintReadWrite, Category = "Obstacle")
	UBoxComponent* ScoreBoxRef;

	UFUNCTION()
	void OnPipeHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnScoreTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
