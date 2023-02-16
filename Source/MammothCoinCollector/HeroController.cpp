// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroController.h"
#include "CoinController.h"
#include "Components/BoxComponent.h"
#include "CoinGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "BulletController.h"

// Sets default values
AHeroController::AHeroController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AHeroController::OnOverlap);

	RootComponent = CollisionBox;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AHeroController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (Speed * CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AHeroController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &AHeroController::MoveHorizontally);
	InputComponent->BindAxis("MoveY", this, &AHeroController::MoveVertically);

	InputComponent->BindAction("Restart", IE_Pressed, this, &AHeroController::OnRestart).bExecuteWhenPaused = true;
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AHeroController::OnShoot);
}

void AHeroController::MoveHorizontally(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AHeroController::MoveVertically(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AHeroController::OnShoot()
{
	UWorld* World = GetWorld();

	if (World)
	{
		FVector Location = GetActorLocation();
		World->SpawnActor<ABulletController>(BulletBlueprint, Location, FRotator::ZeroRotator);
	}
}

void AHeroController::OnRestart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void AHeroController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACoinController::StaticClass()))
	{
		OtherActor->Destroy();

		((ACoinGameMode*)GetWorld()->GetAuthGameMode())->OnCoinCollected();
	}
}

