// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinGameMode.h"
#include "GameWidget.h"

void ACoinGameMode::BeginPlay()
{
	Super::BeginPlay();

	CoinsToCollect = 6;

	ChangeMenuWidget(StartingWidgetClass);
	((UGameWidget*)CurrentWidget)->Load();
}

void ACoinGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACoinGameMode::OnCoinCollected()
{
	CoinsToCollect--;

	if (CoinsToCollect == 0)
	{
		((UGameWidget*)CurrentWidget)->OnGameOver();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

void ACoinGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
