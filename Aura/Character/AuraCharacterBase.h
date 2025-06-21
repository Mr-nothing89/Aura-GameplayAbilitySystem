// Gameplay Ability System.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AuraCharacterBase.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAttributeSet* GetAttributeSet() const {return AttributeSet;}


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(VisibleAnywhere,Category="Combat")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere,Category="Combat")
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

};
