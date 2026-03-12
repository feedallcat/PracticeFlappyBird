// Fill out your copyright notice in the Description page of Project Settings.


#include "OffscreenBoundary.h"
#include "Components/BoxComponent.h"
#include "PracticeFlappyBird/Features/Core/Interface/OffscreenDespawn.h"

// Sets default values
AOffscreenBoundary::AOffscreenBoundary()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AOffscreenBoundary::BeginPlay()
{
	Super::BeginPlay();

	if (BoxRef) {
		BoxRef->OnComponentBeginOverlap.AddDynamic(this, &AOffscreenBoundary::OnOverlap);
	}

}

void AOffscreenBoundary::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if(OtherActor && OtherActor != this) {
		if(auto* Target = Cast<IOffscreenDespawn>(OtherActor)) {
			Target->Despawn();
		}
		if (OtherActor->Implements<UOffscreenDespawn>()) {
			IOffscreenDespawn::Execute_Despawn(this);
		}
	}
}
