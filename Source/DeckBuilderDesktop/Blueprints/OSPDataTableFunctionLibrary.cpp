// Fill out your copyright notice in the Description page of Project Settings.

#include "DeckBuilderDesktop.h"
#include "OSPDataTableFunctionLibrary.h"
#include "Models/GameTypeListModel.h"

UGameTypeListModel* UOSPDataTableFunctionLibrary::ConstructGameTypeListFromDataTable(UDataTable* GameTypeDataTable)
{
	return UGameTypeListModel::ConstructFromGameTypeDataTable(GameTypeDataTable);
}

