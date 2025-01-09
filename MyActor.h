#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT04_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	FVector2D start;

	UPROPERTY()
	float totDist;

	UPROPERTY()
	int32 evCnt;

	UFUNCTION()
	void move();

	UFUNCTION()
	int32 step();

	UFUNCTION()
	float distance(FVector2D first, FVector2D second);

	UFUNCTION()
	int32 createEvent();
};
