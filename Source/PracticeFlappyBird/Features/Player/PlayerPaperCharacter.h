// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "InputMappingContext.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "Delegates/DelegateCombinations.h"
#include "PracticeFlappyBird/Features/Core/PlayerState/MyPlayerState.h"
#include "PracticeFlappyBird/Features/Core/MyGameInstance.h"
#include "PracticeFlappyBird/Features/UI/GameHUDUserWidget.h"
#include "PlayerPaperCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API APlayerPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Player|LifeCycle")
	void Freeze();

	UFUNCTION(BlueprintCallable, Category = "Player|LifeCycle")
	void Unfreeze();

	static APlayerPaperCharacter* GetCurrentPlayer(const UObject* WorldContextObject);

	void TouchedTriggerBox() const;

	UPROPERTY(BlueprintAssignable, Category = "Player|LifeCycle")
	FOnPlayerDied OnPlayerDied;

	void RequestJump();

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

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	AMyPlayerState* MyPS;
};
