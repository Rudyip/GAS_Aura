// Copyright Aura

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

/**
 * Aura玩家控制器
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	// 输入映射上下文
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	// 输入操作
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> InputAction;

	/**
	 * 移动
	 * 
	 * @param InputActionValue 输入值 
	 */
	void Move(const FInputActionValue& InputActionValue);
};
