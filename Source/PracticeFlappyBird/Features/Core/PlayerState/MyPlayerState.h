// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Delegates/DelegateCombinations.h"
#include "MyPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerScoreChanged, int32, NewScore);

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 PlayerScore;

	UPROPERTY(BlueprintAssignable, Category = "Player State")
	FOnPlayerScoreChanged OnPlayerScoreChanged;

	void SetPlayerScore(int32 NewScore);
};
