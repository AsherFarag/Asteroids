#include "SpaceCraft.h"
#include "EngineAPI.h"

SpaceCraft::SpaceCraft()
{
	GetTransform().SetLocalPosition( Vec3{ EngineAPI::GetInstance()->GetWindowWidth() * 0.5f, EngineAPI::GetInstance()->GetWindowHeight() * 0.5f, 0 } ); // Spawns at the Center of the Screen

	// ===== Components =====
	m_RigidBody2D = AddComponent<RigidBody2D>();
	m_RigidBody2D->SetLinearDrag(Vec3{ 4.0f, 4.0f, 0 });
	m_RigidBody2D->SetAngularDrag(3.0f);

	m_SpriteRender = AddComponent<SpriteRenderer>();
	m_SpriteRender->SetSprite("SpaceCraft", 0.5f, 0.5f);

	m_PlayerController = AddComponent<PlayerController>();


}
SpaceCraft::~SpaceCraft() {}