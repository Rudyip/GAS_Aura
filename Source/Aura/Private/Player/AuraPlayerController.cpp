// Copyright Aura


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	// 开启自我复制
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// 如果输入映射上下文没有正确设置，则直接报错
	check(AuraContext);
	// 获取增强输入子系统
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	// 校验增强输入子系统是否有效
	check(InputSubsystem);
	// 添加输入映射上下文
	InputSubsystem->AddMappingContext(AuraContext, 0);
	/* 设置鼠标 */
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData;
	// 不隐藏鼠标光标
	InputModeData.SetHideCursorDuringCapture(false);
	// 鼠标不锁定在视口内
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// 获取增强输入组件
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	// 绑定移动输入处理函数
	EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
		const FRotator Rotator = GetControlRotation();
		// Yaw轴偏转角度（水平偏转角度）
		const FRotator YawRotator(0.f, Rotator.Yaw, 0.0f);
		// 前后方向
		const FVector ForwardDirection = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
		// 左右方向
		const FVector RightDirection = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
		// 添加前后移动输入
		ControllerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		// 添加左右移动输入
		ControllerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
