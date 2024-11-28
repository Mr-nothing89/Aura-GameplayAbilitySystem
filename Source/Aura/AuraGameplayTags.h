// Lucio Martinez.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 *
 * Singleton containing native GameplayTags
 */
struct FAuraGameplayTags
{
	public:
	static const FAuraGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;

	private:
	static FAuraGameplayTags GameplayTags;
};
