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
		//TODO: We are on the server, so listen for target data.
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

	
	AbilitySystemComponent->ServerSetReplicatedTargetData(GetAbilitySpecHandle(),
		GetActivationPredictionKey(),Data,FGameplayTag(),
		AbilitySystemComponent->ScopedPredictionKey);

	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
