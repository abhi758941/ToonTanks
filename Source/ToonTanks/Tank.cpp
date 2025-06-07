// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"

ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(CapsuleComp);
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera-> SetupAttachment(SpringArm); 
}