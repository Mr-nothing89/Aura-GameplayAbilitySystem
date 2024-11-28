// Lucio Martinez.

#pragma once

#include "CoreMinimal.h"

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

	private:
	static FAuraGameplayTags GameplayTags;
};
