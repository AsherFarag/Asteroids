#include "Asteroid.h"
#include "Audio.h"

Asteroid::Asteroid(int a_Size)
{
	m_Tag = "Asteroid";

	// ===== Component Initialising =====
	m_RigidBody2D = AddComponent<RigidBody2D>();
	m_SpriteRenderer = AddComponent<SpriteRenderer>();
	#pragma region Sprite Setting
	std::string AsteroidSprite;
	switch (a_Size)
	{
	case 3:
		AsteroidSprite = "SmallAsteroid";
		break;
	case 2:
		AsteroidSprite = "MediumAsteroid";
		break;
	case 1:
		AsteroidSprite = "LargeAsteroid";
		break;
	}
	m_SpriteRenderer->SetSprite(AsteroidSprite, 0.5f, 0.5f);
	#pragma endregion


	// ===== Member Initialising =====
	m_Size = a_Size;
}

Asteroid::Asteroid(int a_Size, Transformation* a_CopyTransformation)
{
	new Asteroid(a_Size);

	m_Transform = *a_CopyTransformation;
}

Asteroid::Asteroid(int a_Size, Vec3 a_SpawnPosition, float a_Rotation, float a_Speed)
{
	m_Tag = "Asteroid";

	// ===== Component Initialising =====
	m_RigidBody2D = AddComponent<RigidBody2D>();

	m_CircleCollider2D = AddComponent<CircleCollider2D>();
	m_CircleCollider2D->SetRadius(60.0f / a_Size);

	m_SpriteRenderer = AddComponent<SpriteRenderer>();
	#pragma region Sprite Setting
	std::string AsteroidSprite;
	switch (a_Size)
	{
	case 3:
		AsteroidSprite = "SmallAsteroid";
		break;
	case 2:
		AsteroidSprite = "MediumAsteroid";
		break;
	case 1:
		AsteroidSprite = "LargeAsteroid";
		break;
	}
	m_SpriteRenderer->SetSprite(AsteroidSprite, 0.5f, 0.5f);
	#pragma endregion


	// ===== Member Initialising =====
	m_Size = a_Size;

	m_Transform.SetLocalRotation(a_Rotation);
	m_Transform.SetLocalPosition(a_SpawnPosition);
	m_RigidBody2D->SetLinearVelocity(a_Speed);

}

Asteroid::~Asteroid() { }

void Asteroid::Update(float a_DeltaTime) 
{
	GameObject::Update(a_DeltaTime);

	if (m_CircleCollider2D->m_IsColliding)
	{
		Destroy();
	}
}


void Asteroid::Destroy()
{
	EngineAPI::GetGameManager()->AddScore(100 * m_Size);

	if (m_Size < 3)
	{
		SpawnSmallerAsteroids(m_Size + 1);
	}

	switch (m_Size)
	{
	case 1:
		PlaySound(*Resource::GetResource<Audio>("bangLarge")->GetSound());
		break;
	case 2:
		PlaySound(*Resource::GetResource<Audio>("bangMedium")->GetSound());
		break;
	case 3:
		PlaySound(*Resource::GetResource<Audio>("bangSmall")->GetSound());
		break;
	}

	delete this;
}

void Asteroid::SpawnSmallerAsteroids(int a_Size)
{
	EngineAPI::InstantiateObject<Asteroid>( a_Size, this->m_Transform.GetLocalPosition(), this->m_Transform.GetLocalRotation() - 15, this->GetComponent<RigidBody2D>()->GetLinearSpeed() );
	EngineAPI::InstantiateObject<Asteroid>( a_Size, this->m_Transform.GetLocalPosition(), this->m_Transform.GetLocalRotation() + 15, this->GetComponent<RigidBody2D>()->GetLinearSpeed() );
}
