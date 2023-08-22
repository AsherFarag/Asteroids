#include "Asteroid.h"

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

	// TODO: Copy Transformation Info from Parent
}

Asteroid::Asteroid(int a_Size, Vec3 a_SpawnPosition, float a_Rotation, float a_Speed)
{
	m_Tag = "Asteroid";

	// ===== Component Initialising =====
	m_RigidBody2D = AddComponent<RigidBody2D>();
	m_CircleCollider2D = AddComponent<CircleCollider2D>();
	m_CircleCollider2D->SetRadius(60.0f / a_Size); // Temp
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

Asteroid::~Asteroid()
{
	EngineAPI::GetGameManager()->AddScore(100 * m_Size);

	if (m_Size < 3)
	{
		SpawnSmallerAsteroids(m_Size - 1);
	}
}

void Asteroid::SpawnSmallerAsteroids(int a_Size)
{

}
