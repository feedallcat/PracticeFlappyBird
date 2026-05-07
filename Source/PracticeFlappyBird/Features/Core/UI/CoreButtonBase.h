// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CoreButtonBase.generated.h"

class UCommonTextBlock;

/**
 * 
 */
UCLASS()
class PRACTICEFLAPPYBIRD_API UCoreButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Button Text")
	FText ButtonText;

protected:
	UPROPERTY(meta = (BindWidgetOptional))
	UCommonTextBlock* CTB_Text;

	virtual void NativePreConstruct() override;
};
