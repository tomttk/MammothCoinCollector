// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWidget.h"

void UGameWidget::Load()
{
	const FName TextBlockName = FName(TEXT("ScoreTextBlock"));

	if (ScoreText == nullptr)
	{
		ScoreText = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
	}
}

void UGameWidget::OnGameOver()
{
	if (ScoreText == nullptr) 
	{
		ScoreText->SetText(FText::FromString(FString(TEXT("You Win !\nPress R to Restart"))));
	}
}