#include "SpaceCraft.h"

SpaceCraft::SpaceCraft()
{
	GetTransform().SetLocalPosition(Vec3{ 400, 400, 0 });
	m_SpriteRender = AddComponent<SpriteRenderer>();
	m_SpriteRender->SetSprite("SpaceCraft");
}
SpaceCraft::~SpaceCraft() {}