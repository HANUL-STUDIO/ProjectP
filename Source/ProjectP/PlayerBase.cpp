#include "PlayerBase.h"
#include "Components/InputComponent.h"


APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;
}


void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
}


void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


////////////////////////////
// 작성자(홍한울)
// 공통 입력 바인딩 설정
// 파라미터 설명: PlayerInputComponent - 입력 컴포넌트
// 반환값 설명: 없음
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerBase::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerBase::LookUp);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlayerBase::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &APlayerBase::StopJump);
	PlayerInputComponent->BindAction(TEXT("UseSkill"), IE_Pressed, this, &APlayerBase::UseCharacterSkill);
}



void APlayerBase::MoveForward(float Value)
{
	if (Controller != nullptr && !FMath::IsNearlyZero(Value))
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}


void APlayerBase::MoveRight(float Value)
{
	if (Controller != nullptr && !FMath::IsNearlyZero(Value))
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}


void APlayerBase::Turn(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	{
		AddControllerYawInput(Value);
	}
}


void APlayerBase::LookUp(float Value)
{
	if (!FMath::IsNearlyZero(Value))
	{
		AddControllerPitchInput(Value);
	}
}


void APlayerBase::StartJump()
{
	Jump();
}


void APlayerBase::StopJump()
{
	StopJumping();
}


void APlayerBase::UseCharacterSkill()
{
}

