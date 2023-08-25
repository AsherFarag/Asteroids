#include "SpaceCraft.h"
#include "EngineAPI.h"
#include "GameObject.h"

SpaceCraft::SpaceCraft()
{
	m_Tag = "SpaceCraft";

	// Spawn at the Center of the Screen
	GetTransform().SetLocalPosition( Vec3{ EngineAPI::GetInstance()->GetWindowWidth() * 0.5f, EngineAPI::GetInstance()->GetWindowHeight() * 0.5f, 0 } );
	GetTransform().SetLocalRotation(90);

	#pragma region Component Instatiation

	m_RigidBody2D = AddComponent<RigidBody2D>();
	m_RigidBody2D->SetLinearDrag(Vec3{ 4.0f, 4.0f, 0 });
	m_RigidBody2D->SetAngularDrag(3.0f);

	m_CircleCollider2D = AddComponent<CircleCollider2D>();
	m_CircleCollider2D->SetRadius(22.5f);

	m_SpriteRender = AddComponent<SpriteRenderer>();
	m_SpriteRender->SetSprite("SpaceCraft", 0.5f, 0.5f);

	m_PlayerController = AddComponent<PlayerController>();

	#pragma endregion
}

SpaceCraft::~SpaceCraft() { }

void SpaceCraft::Update(float a_DeltaTime)
{
	GameObject::Update(a_DeltaTime);

	if (m_CircleCollider2D->m_IsColliding)
	{
		Destroy();
	}
}

void SpaceCraft::Destroy()
{
	if (EngineAPI::GetGameManager()->GetLives() > 0) // On Death State with more than 0 Lives left
	{
		EngineAPI::GetGameManager()->AddLives(-1); // Subracts a Life
		delete this;
		EngineAPI::GetGameManager()->RespawnPlayer();
	}
	else // On Death with 0 Lives
	{
		EngineAPI::GetGameManager()->m_GameOver = true;
		delete this;
	}
}
