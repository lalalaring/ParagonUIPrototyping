// Fill out your copyright notice in the Description page of Project Settings.

#include "DeckBuilderDesktop.h"
#include "CardsDataFilterByProperty.h"


UCardsDataFilterByProperty::UCardsDataFilterByProperty(class FObjectInitializer const & ObjectInitializer)
	: Super(ObjectInitializer)
{
	static FName FNAME_CardsDataFilter_ByProperty(TEXT("Stat"));
	TypeName = FNAME_CardsDataFilter_ByProperty;
}

TArray<FCardData> UCardsDataFilterByProperty::FilteredCardsData(TArray<FCardData> CardsData)
{
	if (IsActive())
	{
		return CardsData.FilterByPredicate([=](const FCardData& CardData) {
			UProperty* Property = CardData.StaticStruct()->FindPropertyByName(FName(*ValueString));
			if (Property)
			{
				if (Property->IsA(UFloatProperty::StaticClass()))
				{
					UFloatProperty *NumericProp = CastChecked<UFloatProperty>(Property);
					float value = NumericProp->GetPropertyValue_InContainer(&CardData);
					if (value != -0.0 && value != 0.0)
					{
						return true;
					}
				}
				else if (Property->IsA(UStrProperty::StaticClass()))
				{
					UStrProperty *StrProp = CastChecked<UStrProperty>(Property);
					FString Value = StrProp->GetPropertyValue_InContainer(&CardData);
					if (Value.Len() > 0)
					{
						return true;
					}
				}
			}
			return false;
		});
	}
	return CardsData;
}

