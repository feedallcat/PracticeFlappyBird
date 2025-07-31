// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "InputMappingContext.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "PlayerPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API APlayerPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	APlayerPaperCharacter();
	
protected:

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Input");
	UInputMappingContext* ImcDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Input");
	UInputAction* IaJump;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Sprite");
	UPaperFlipbook* FbIdle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Sprite");
	UPaperFlipbook* FbJumpUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Sprite");
	UPaperFlipbook* FbJumpDown;

	void OnJumpInput(const FInputActionValue& Value);

};
