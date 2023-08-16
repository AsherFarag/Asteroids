#pragma once

#include "GameObject.h"
#include "RigidBody2D.h"
#include "SpriteRenderer.h"
#include "PlayerController.h"

class SpaceCraft
	: public GameObject
{
public:
	SpaceCraft();
	~SpaceCraft();

private:
	// ===== Components =====
	RigidBody2D*      m_RigidBody2D;
	SpriteRenderer*	  m_SpriteRender;
	PlayerController* m_PlayerController;
};

