// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectile::AProjectile(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;

	TrailParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailParticles"));
	TrailParticles->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay(){
	Super::BeginPlay();
	
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

	UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
}

// Called every frame
void AProjectile::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, FVector NormalImpulse, const FHitResult &Hit){
	auto MyOwner = GetOwner();
	if(!MyOwner) { return; }

	auto MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();

	if(OtherActor && OtherActor != this && OtherActor != MyOwner){
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
		if(HitParticle){
			UGameplayStatics::SpawnEmitterAtLocation(this, HitParticle, GetActorLocation(), GetActorRotation());
		}
		if(HitSound){
			UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
		}
		if(HitCameraShakeClass){
			GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass);
		}
	}
	Destroy();
}
