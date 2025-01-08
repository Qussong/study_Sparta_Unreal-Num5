// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class ACTORRANDOMMOVE_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	AMyActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	// Essential
	void Move();
	int32 Step();
	// Challenge
	void MoveLength(FVector PrevPos, FVector NewPos);
	void Event();
	
private:
	float Timer;
	int32 MoveCnt;
	int32 EventCnt;
};
