// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorRandomMoveGameMode.h"
#include "ActorRandomMoveCharacter.h"
#include "UObject/ConstructorHelpers.h"

AActorRandomMoveGameMode::AActorRandomMoveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
