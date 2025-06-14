// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


ATower::ATower()
{

}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
    GetWorldTimerManager().SetTimer(FireRateTimerHandle , this , &ATower::CheckFireCondition , FireRate , true);
}
void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (IsInRange())
    {
        RotateTurret(Tank->GetActorLocation());
    }    
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}

void ATower::CheckFireCondition()
{
    if(Tank && IsInRange() && Tank->bAlive)
    {
        Fire();
    }
}

bool ATower::IsInRange()
{
    if(Tank)
    {
        return FireRange > FVector::Dist(GetActorLocation() , Tank->GetActorLocation());
    }
    return false;
}
