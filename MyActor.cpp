#include "MyActor.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0, 0);
	totDist = 0;
	evCnt = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
	UE_LOG(LogTemp, Log, TEXT("Total move distance : %f"), totDist);
	UE_LOG(LogTemp, Log, TEXT("Total event : %d"), evCnt);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

int32 AMyActor::createEvent()
{
	int32 randnum = FMath::RandRange(1, 100);

	if (randnum <= 50)
	{
		UE_LOG(LogTemp, Log, TEXT("Yes Event"));
		return 1;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("No Event."));
		return 0;
	}
}

void AMyActor::move()
{
	FVector2D current = start;

	for (int32 i = 0; i < 10; i++)
	{
		int32 stepx = step();
		int32 stepy = step();

		FVector2D next(current.X + stepx, current.Y + stepy);

		if (next.X - current.X <= 2 && next.Y - current.Y <= 2)
		{
			float dist = distance(current, next);
			totDist += dist;

			UE_LOG(LogTemp, Log, TEXT("Move Count : %d, Now Position (%f, %f), Move distance : %f"), i + 1, next.X, next.Y, dist);

			evCnt += createEvent();

			current = next;
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("false move."));
		}
	}
}
