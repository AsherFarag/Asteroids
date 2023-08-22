#pragma once

#include "GameObject.h"
#include "RigidBody2D.h"
#include "SpriteRenderer.h"
#include "CircleCollider2D.h"
#include "PlayerController.h"

class SpaceCraft
	: public GameObject
{
public:
	SpaceCraft();
	~SpaceCraft();

	virtual void Destroy() override { delete this; }

private:
	// ===== Components =====
	RigidBody2D*      m_RigidBody2D;
	SpriteRenderer*	  m_SpriteRender;
	CircleCollider2D* m_CircleCollider2D;
	PlayerController* m_PlayerController;
};

