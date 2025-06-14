// Gameplay Ability System.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;
class URotatingMovementComponent;
class USphereComponent;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAuraEffectActor();

	

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(TSubclassOf<UGameplayEffect> GameplayEffectClass,AActor* Target);

	UPROPERTY(EditAnywhere,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<URotatingMovementComponent> RotatingMovement;
	

};
