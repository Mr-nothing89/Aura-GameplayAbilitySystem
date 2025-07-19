// Gameplay Ability System.


#include "TargetDataUnderMouse_AbilityTask.h"

UTargetDataUnderMouse_AbilityTask* UTargetDataUnderMouse_AbilityTask::CreateTargetDataUnderMouse(
	UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse_AbilityTask* MyObj = NewAbilityTask<UTargetDataUnderMouse_AbilityTask>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse_AbilityTask::Activate()
{
	//Super::Activate();
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,CursorHit);
	ValidData.Broadcast(CursorHit.ImpactPoint);
}
