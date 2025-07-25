// Gameplay Ability System.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AuraAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:

	static UAuraAssetManager& Get();

protected:

	void StartInitialLoading() override;
	
};
