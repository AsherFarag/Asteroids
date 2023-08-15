#pragma once

#include "GameObject.h"
#include "SpriteRenderer.h"

class SpaceCraft
	: public GameObject
{
public:
	SpaceCraft();
	~SpaceCraft();

private:
	// ===== Components =====
	SpriteRenderer* m_SpriteRender;
};

