#pragma once
#include "GameObject.h"
#include "RigidBody2D.h"
#include "SpriteRenderer.h"
#include "CircleCollider2D.h"
#include "PlayerController.h"

class Bullet :
    public GameObject
{
public:
	Bullet(Transformation* a_CopyTransform, float a_Speed);
	~Bullet();

	virtual void Update(float a_DeltaTime) override;
 	virtual void Destroy() override { delete this; }

private:
	// ===== LifeTime =====
	float m_CurrentLifeTime = 0.0f;
	float m_MaxLifeTime = 5.0f;


	// ===== Components =====
	RigidBody2D* m_RigidBody2D;
	SpriteRenderer* m_SpriteRender;
	CircleCollider2D* m_CircleCollider2D;
	PlayerController* m_PlayerController;
};

