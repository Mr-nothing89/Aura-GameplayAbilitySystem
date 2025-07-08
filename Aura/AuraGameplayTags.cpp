// Gameplay Ability System.


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 *Primary Attributes
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Primary.Strength",
		FString("Increases physical damage"));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Primary.Intelligence",
		FString("Increases magical damage"));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Primary.Resilience",
		FString("Increases armor and armor penetration"));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Primary.Vigor",
		FString("Increases health"));

	/*
	 *Secondary Attributes
	 */
	
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag("Attributes.Secondary.Armor",
		FString("Reduces damage taken, improves Block Chance"));

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.ArmorPenetration",
		FString("Ignores Percentage of enemy Armor, increases Critical Hit Chance"));

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.BlockChance",
		FString("Chance to cut incoming damage in half"));

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.CriticalHitChance",
		FString("Chance to double damage plus Critical Hit bonus"));

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.CriticalHitDamage",
		FString("Bonus Damage added when a critical hit is scored"));

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.CriticalHitResistance",
		FString("Reduces Critical Hit Chance of attacking enemies"));

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.HealthRegeneration",
		FString("Amount of Health regenerated every 1 second"));

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.ManaRegeneration",
		FString("Amount of Mana regenerated every 1 second"));

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.MaxHealth",
		FString("Maximum amount of Health obtainable"));

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Attributes.Secondary.MaxMana",
		FString("Maximum amount of Mana obtainable"));

	/*
	 * Input Tags
	 */
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"InputTag.LMB",
		FString("Input Tag for Left Mouse Button"));

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"InputTag.RMB",
		FString("Input Tag for Right Mouse Button"));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"InputTag.1",
		FString("Input Tag for 1 key"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"InputTag.2",
		FString("Input Tag for 2 key"));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"InputTag.3",
		FString("Input Tag for 3 key"));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"InputTag.4",
		FString("Input Tag for 4 key"));
}
