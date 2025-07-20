// Gameplay Ability System.


#include "TargetDataUnderMouse_AbilityTask.h"

#include "AbilitySystemComponent.h"

UTargetDataUnderMouse_AbilityTask* UTargetDataUnderMouse_AbilityTask::CreateTargetDataUnderMouse(
	UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse_AbilityTask* MyObj = NewAbilityTask<UTargetDataUnderMouse_AbilityTask>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse_AbilityTask::Activate()
{
	//Super::Activate();
	if (Ability->GetCurrentActorInfo()->IsLocallyControlled())
	{
		SendMouseCursorData();
	}
	else
	{
		const FGameplayAbilitySpecHandle SpecHandle = GetAbilitySpecHandle();
		const FPredictionKey ActivationPredictionKey = GetActivationPredictionKey();
		AbilitySystemComponent->AbilityTargetDataSetDelegate(SpecHandle,ActivationPredictionKey).AddUObject(
			this,&UTargetDataUnderMouse_AbilityTask::OnTargetDataReplicatedCallBack);

		if (!AbilitySystemComponent->CallReplicatedTargetDataDelegatesIfSet(SpecHandle,ActivationPredictionKey))
		{
			SetWaitingOnRemotePlayerData();
		}
	}
	
}

void UTargetDataUnderMouse_AbilityTask::SendMouseCursorData()
{
	FScopedPredictionWindow ScopedPrediction(AbilitySystemComponent.Get());
	
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,CursorHit);

	FGameplayAbilityTargetDataHandle DataHandle;
	FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit();
	Data->HitResult = CursorHit;
	DataHandle.Add(Data);

	
	AbilitySystemComponent.Get()->ServerSetReplicatedTargetData(GetAbilitySpecHandle(),
		GetActivationPredictionKey(),DataHandle,FGameplayTag(),
		AbilitySystemComponent->ScopedPredictionKey);

	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}

void UTargetDataUnderMouse_AbilityTask::OnTargetDataReplicatedCallBack(
	const FGameplayAbilityTargetDataHandle& DataHandle, FGameplayTag ActivationTag)
{
	AbilitySystemComponent->ConsumeClientReplicatedTargetData(GetAbilitySpecHandle(),GetActivationPredictionKey());
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
