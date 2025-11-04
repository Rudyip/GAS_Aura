// Copyright Aura


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	// 角色朝向移动的方向旋转
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// 设置水平旋转的速度
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	// 把角色移动约束在平面上
	GetCharacterMovement()->bConstrainToPlane = true;
	// 开始就把角色放到平面上
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	/* 关闭控制器旋转控制 */
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}
