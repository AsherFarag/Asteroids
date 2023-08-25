#include "Bullet.h"

Bullet::Bullet(Transformation* a_CopyTransform, float a_Speed)
{
	m_Tag = "Bullet";

	m_Transform = *a_CopyTransform;

	// ===== Components =====
	m_RigidBody2D = AddComponent<RigidBody2D>();
	m_RigidBody2D->SetLinearVelocity(a_Speed);

	m_CircleCollider2D = AddComponent<CircleCollider2D>();
	m_CircleCollider2D->SetRadius(2.5f);

	m_SpriteRender = AddComponent<SpriteRenderer>();
	m_SpriteRender->SetSprite("Bullet", 0.5f, 0.5f);
}

Bullet::~Bullet()
{
}

void Bullet::Update(float a_DeltaTime)
{
	GameObject::Update(a_DeltaTime);

	m_CurrentLifeTime += a_DeltaTime;

	if (m_CircleCollider2D->m_IsColliding || m_CurrentLifeTime >= m_MaxLifeTime)
	{
		Destroy();
	}
}
