// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OffscreenDespawn.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UOffscreenDespawn : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PRACTICEFLAPPYBIRD_API IOffscreenDespawn
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Object Behavior")
	void Despawn();
};
