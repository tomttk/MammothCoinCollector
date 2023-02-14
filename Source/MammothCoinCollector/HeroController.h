// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HeroController.generated.h"

UCLASS()
class MAMMOTHCOINCOLLECTOR_API AHeroController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHeroController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		UShapeComponent* CollisionBox;

	UPROPERTY(EditAnywhere)
		float Speed = 10.0f;

	FVector CurrentVelocity;

	void MoveHorizontally(float AxisValue);
	void MoveVertically(float AxisValue);

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
