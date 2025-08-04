// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MainGameState.h"
#include "MainGameStateBase.generated.h"

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API AMainGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMainGameStateBase();

	UPROPERTY(ReplicatedUsing = OnRep_PlayState, BlueprintReadOnly, Category = "Game State")
	EMainGameState CurrentGameState;

	UFUNCTION(BlueprintCallable, Category = "Game State")
	void SetGameState(EMainGameState NewState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged, EMainGameState, NewState);

	UPROPERTY(BlueprintAssignable, Category = "Game State")
	FOnGameStateChanged OnGameStateChanged;

protected:

	UFUNCTION()
	void OnRep_PlayState();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
