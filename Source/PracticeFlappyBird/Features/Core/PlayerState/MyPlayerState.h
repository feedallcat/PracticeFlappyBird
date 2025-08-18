// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 PlayerScore;
};
