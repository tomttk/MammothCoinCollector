// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinController.h"
#include "Components/BoxComponent.h"

// Sets default values
ACoinController::ACoinController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void ACoinController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

