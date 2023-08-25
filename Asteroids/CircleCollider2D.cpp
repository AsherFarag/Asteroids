#include "CircleCollider2D.h"
#include "EngineAPI.h"

CircleCollider2D::CircleCollider2D()
{
}

CircleCollider2D::CircleCollider2D(float a_Radius)
{
	m_Radius = a_Radius;
}

CircleCollider2D::~CircleCollider2D()
 {
	
}

void CircleCollider2D::SetUpComponent()
{
	EngineAPI::GetPhysicsManager()->RegisterCollider(this);
	m_AttachedTransform = &m_AttachedObject->GetTransform();
	m_Tag = *m_AttachedObject->GetTag();
}

void CircleCollider2D::Update(float a_DeltaTime)
{
	//DrawCircleLines(m_AttachedTransform->GetLocalPosition().x, EngineAPI::GetWindowHeight() - m_AttachedTransform->GetLocalPosition().y, m_Radius, RED);
	if (m_IsColliding)
	{
		OnTrigger();
	}
}

void CircleCollider2D::Destroy()
{
	EngineAPI::GetPhysicsManager()->UnregisterCollider(this);
	delete this;
}

void CircleCollider2D::OnTrigger()
{
	m_IsColliding = true;
}
