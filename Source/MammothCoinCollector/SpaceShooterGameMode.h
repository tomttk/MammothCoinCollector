// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MAMMOTHCOINCOLLECTOR_API ASpaceShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

	float MINIMUM_INTERVAL = 0.5f;
	float MAXIMUM_INTERVAL = 2.0f;
	float TIME_TO_MINIMUM_INTERVAL = 30.0f;

public:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemyController> EnemyBlueprint;

	float EnemyTimer;
	float GameTimer;

protected:

	int Score = 0;
};
