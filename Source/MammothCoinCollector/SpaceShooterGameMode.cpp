// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShooterGameMode.h"
#include "EnemyController.h"

void ASpaceShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ASpaceShooterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameTimer += DeltaTime;
	EnemyTimer -= DeltaTime;
	if (EnemyTimer <= 0.0f)
	{
		float difficultyPercentage = FMath::Min(GameTimer / TIME_TO_MINIMUM_INTERVAL, 1.0f);
		EnemyTimer = MAXIMUM_INTERVAL - (MAXIMUM_INTERVAL - MINIMUM_INTERVAL) * difficultyPercentage;

		UE_LOG(LogTemp, Warning, TEXT("Timer is %f"), EnemyTimer);

		UWorld* World = GetWorld();
		if (World)
		{
			FVector Location = FVector(600.0f, FMath::RandRange(-800.0f, 800.0f), 70.f);
			World->SpawnActor<AEnemyController>(EnemyBlueprint, Location, FRotator::ZeroRotator);
		}
	}
}