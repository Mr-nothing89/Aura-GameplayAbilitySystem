// Gameplay Ability System.


#include "AuraInputConfigDataAsset.h"

const UInputAction* UAuraInputConfigDataAsset::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for (const FAuraInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag.MatchesTagExact(InputTag))
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp,Error,TEXT(
			"Can't find Ability Input Action for Input Tag [%s] on InputConfig [%s]."),
			*InputTag.ToString(),*GetNameSafe(this));
	}

	return nullptr;
}
