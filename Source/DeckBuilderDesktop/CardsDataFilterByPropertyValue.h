// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CardsDataFilter.h"
#include "CardsDataFilterByPropertyValue.generated.h"

/**
 * 
 */
UCLASS()
class DECKBUILDERDESKTOP_API UCardsDataFilterByPropertyValue : public UCardsDataFilter
{
	GENERATED_UCLASS_BODY()
	

public:
	virtual TArray<FCardData> FilteredCardsData(TArray<FCardData> CardsData) override;
	
	
};