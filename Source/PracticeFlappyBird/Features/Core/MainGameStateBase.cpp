// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameStateBase.h"
#include "Net/UnrealNetwork.h"

AMainGameStateBase::AMainGameStateBase() {
	CurrentGameState = EMainGameState::WaitingToStart;
}

void AMainGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMainGameStateBase, CurrentGameState);
}

void AMainGameStateBase::SetGameState(EMainGameState NewState) {
	if (CurrentGameState != NewState) {
		CurrentGameState = NewState;
		OnRep_PlayState();
	}
}

void AMainGameStateBase::OnRep_PlayState()
{
	OnGameStateChanged.Broadcast(CurrentGameState);
}