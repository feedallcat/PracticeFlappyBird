// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CoreGameScreenBase.generated.h"

/**
 *
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UCoreGameScreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
};
