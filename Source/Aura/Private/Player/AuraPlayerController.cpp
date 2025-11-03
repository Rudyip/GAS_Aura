// Copyright Aura


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

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
