#include "Actors/MyActor.h"

AMyActor::AMyActor()
	: MoveCnt(0)
	  , Timer(0.f)
	  , EventCnt(0)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "MyActor Spawned.");
	UE_LOG(LogTemp, Log, TEXT("MyActor Spawned."));
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveCnt < 10)
	{
		if (Timer < 1.f)
		{
			Timer += DeltaTime;
		}
		else
		{
			Move();
			Timer = 0.f;
		}
	}
}

void AMyActor::Move()
{
	int Scale = 100.f;

	int DeltaX = Step() * Scale;
	int DeltaY = Step() * Scale;
	int DirectionX = FMath::RandBool() ? 1 : (-1);
	int DirectionY = FMath::RandBool() ? 1 : (-1);

	FVector PrevPos = GetActorLocation();
	float NewPosX = (DeltaX * DirectionX) + PrevPos.X;
	float NewPosY = (DeltaY * DirectionY) + PrevPos.Y;
	FVector NewPos = FVector(NewPosX, NewPosY, PrevPos.Z);
	SetActorLocation(NewPos);

	++MoveCnt;

	Event();
	
	FString DebugMessage_MoveCnt = FString::Printf(TEXT("MoveCnt = %d"), MoveCnt);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, DebugMessage_MoveCnt);
	UE_LOG(LogTemp, Log, TEXT("Move Cnt : %d"), MoveCnt);

	FString DebugMessage_NewPos = FString::Printf(
		TEXT("Actor Pos : (%f, %f, %f)"), NewPosX / Scale, NewPosY / Scale, GetActorLocation().Z);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, DebugMessage_NewPos);
	UE_LOG(LogTemp, Log, TEXT("Actor Pos : (%f, %f, %f)"), NewPosX/Scale, NewPosY/Scale, GetActorLocation().Z);

	MoveLength(PrevPos / Scale, NewPos / Scale);
	
	if (MoveCnt == 10)
	{
		UE_LOG(LogTemp, Log, TEXT("EventCnt : %d"), EventCnt);
	}
}

int32_t AMyActor::Step()
{
	bool bRandomBoolean = FMath::RandBool();
	return bRandomBoolean ? 1 : 0;
}

void AMyActor::MoveLength(FVector PrevPos, FVector NewPos)
{
	float MoveDistance = FMath::Sqrt(
		FMath::Pow(static_cast<float>(NewPos.X - PrevPos.X), 2.0f) +
		FMath::Pow(static_cast<float>(NewPos.Y - PrevPos.Y), 2.0f)
	);
	UE_LOG(LogTemp, Log, TEXT("%d_Move Distance : %f"), MoveCnt, MoveDistance);
}

void AMyActor::Event()
{
	bool bEvent = FMath::RandBool();
	if (bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("Event"));
		++EventCnt;
	}
}
