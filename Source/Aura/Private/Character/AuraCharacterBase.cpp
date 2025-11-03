// Copyright Aura


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	// 关闭tick
	PrimaryActorTick.bCanEverTick = false;
	// 创建武器网格体组件
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	// 设置武器附着点
	Weapon->SetupAttachment(GetMesh(), "WeaponHandSocket");
	// 关闭武器碰撞
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

