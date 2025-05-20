// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlackWhiteGameMode.h"
#include "BlackWhiteCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABlackWhiteGameMode::ABlackWhiteGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
