// Gameplay Ability System.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "TargetDataUnderMouse_AbilityTask.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature,const FGameplayAbilityTargetDataHandle&,DataHandle);

/**
 * 
 */
UCLASS()
class AURA_API UTargetDataUnderMouse_AbilityTask : public UAbilityTask
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Ability|Tasks",meta=(HidePin="OwningAbility",DefaultToSelf="OwningAbility",
		BlueprintInternalUseOnly="true",DisplayName="TargetDataUnderMouse"))
	static UTargetDataUnderMouse_AbilityTask* CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility);

	UPROPERTY(BlueprintAssignable)
	FMouseTargetDataSignature ValidData;

private:

	virtual void Activate() override;
	void SendMouseCursorData();
	
};
