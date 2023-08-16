#include "SpaceCraft.h"
#include "EngineAPI.h"

SpaceCraft::SpaceCraft()
{
	GetTransform().SetLocalPosition(Vec3{ EngineAPI::GetInstance()->GetWindowWidth() * 0.5f, EngineAPI::GetInstance()->GetWindowHeight() * 0.5f, 0}); // Spawns at the Center of the Screen
	m_SpriteRender = AddComponent<SpriteRenderer>();
	m_SpriteRender->SetSprite("SpaceCraft", 0.5f, 0.5f);
}
SpaceCraft::~SpaceCraft() {}