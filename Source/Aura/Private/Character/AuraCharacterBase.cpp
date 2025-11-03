// Copyright Aura


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	// 关闭tick
	PrimaryActorTick.bCanEverTick = false;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

