// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPipe.h"
#include "Components/BoxComponent.h"
#include "PracticeFlappyBird/Features/Core/Interface/ScoreCollector.h"
#include "PracticeFlappyBird/Features/Core/Interface/MortalEntity.h"

// Sets default values
AMovingPipe::AMovingPipe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMovingPipe::BeginPlay()
{
	Super::BeginPlay();

	if (UpperPipeRef) {
		UpperPipeRef->OnComponentBeginOverlap.AddDynamic(this, &AMovingPipe::OnPipeHit);
	}

	if(LowerPipeRef) {
		LowerPipeRef->OnComponentBeginOverlap.AddDynamic(this, &AMovingPipe::OnPipeHit);
	}

	if(ScoreBoxRef) {
		ScoreBoxRef->OnComponentBeginOverlap.AddDynamic(this, &AMovingPipe::OnScoreTriggered);
	}
	
}

void AMovingPipe::OnPipeHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor && OtherActor != this) {
		if(OtherActor->Implements<UMortalEntity>()) {
			IMortalEntity::Execute_Die(OtherActor);
		}
	}
}

void AMovingPipe::OnScoreTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this) {
		if (OtherActor->Implements<UScoreCollector>()) {
			IScoreCollector::Execute_AddScore(OtherActor, 1);
		}
	}
}

void AMovingPipe::Despawn_Implementation() {
	Destroy();
}