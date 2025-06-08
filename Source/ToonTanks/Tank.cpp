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
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward" , this , &ATank::Move);

}

void ATank::Move(float Value)
{
    UE_LOG(LogTemp, Display, TEXT("value is %f"),Value);
}
