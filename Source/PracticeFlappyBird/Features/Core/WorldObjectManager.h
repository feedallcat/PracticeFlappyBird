// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "PracticeFlappyBird/Features/Core/GameMode/MainGameModeBase.h"
#include "WorldObjectManager.generated.h"

UCLASS()
class PRACTICEFLAPPYBIRD_API AWorldObjectManager : public AActor
{
	GENERATED_BODY()

public:

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Boundaries")
	ATriggerBox* TopTriggerBox;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Boundaries")
	ATriggerBox* BottomTriggerBox;

	UFUNCTION()
	void HandleTriggerBoxOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
