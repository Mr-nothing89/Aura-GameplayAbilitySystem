// Gameplay Ability System.


#include "CharacterClassInfoDataAsset.h"

FCharacterClassDefaultInfo UCharacterClassInfoDataAsset::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
