// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathZone.h"
#include "Components/BoxComponent.h"
#include "PracticeFlappyBird/Features/Core/Interface/MortalEntity.h"

// Sets default values
ADeathZone::ADeathZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADeathZone::BeginPlay()
{
	Super::BeginPlay();

	if (BoxRef) {
		BoxRef->OnComponentBeginOverlap.AddDynamic(this, &ADeathZone::OnOverlap);
	}
	
}

void ADeathZone::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if(OtherActor && OtherActor != this) {
		if (OtherActor->Implements<UMortalEntity>()) {
			IMortalEntity::Execute_Die(OtherActor);
		}
	}
}


