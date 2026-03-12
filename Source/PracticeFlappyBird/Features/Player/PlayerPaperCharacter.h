// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Delegates/DelegateCombinations.h"
#include "PracticeFlappyBird/Features/Core/GameDefinitions.h"
#include "PracticeFlappyBird/Features/Core/Interface/MortalEntity.h"
#include "PracticeFlappyBird/Features/Core/Interface/ScoreCollector.h"
#include "PlayerPaperCharacter.generated.h"

class UPaperFlipbook;
class AMyPlayerState;
class UGameHUDUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStatusChanged, EPlayerStatus, NewStatus);

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API APlayerPaperCharacter : public APaperCharacter, public IMortalEntity, public IScoreCollector
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Player|LifeCycle")
	void Freeze();

	UFUNCTION(BlueprintCallable, Category = "Player|LifeCycle")
	void Unfreeze();

	static APlayerPaperCharacter* GetCurrentPlayer(const UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable, Category = "Player|LifeCycle")
	FOnPlayerStatusChanged OnPlayerStatusChanged;

	void RequestJump();

	virtual void Die_Implementation() override;
	virtual void AddScore_Implementation(int32 Score) override;

protected:

	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Sprite")
	UPaperFlipbook* FbIdle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Sprite")
	UPaperFlipbook* FbJumpUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Sprite")
	UPaperFlipbook* FbJumpDown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sprite")
	UPaperFlipbook* FbDead;

	UFUNCTION()
	void OnGameStateChanged(EMainGameState NewState);

	class UGameHUDUserWidget* GetGameHud();

	UFUNCTION(BlueprintCallable, Category = "Player|State")
	class AMyPlayerState* GetMyPlayerState();

private:

	UPROPERTY(Transient)
	AMyPlayerState* MyPS;


};
