// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CoreMenuScreenBase.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UCoreMenuScreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
	
};
