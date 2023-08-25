#include "RigidBody2D.h"
#include "GameObject.h"
#include "Component.h"
#include "raylib.h"

void RigidBody2D::Update(float a_DeltaTime)
{
	// ===== Linear Movement =====
	m_LinearVelocity = Vector3Add( m_LinearVelocity, Vector3Scale(m_LinearAcceleration, a_DeltaTime) ); // Adds the Acceleration
	#pragma region Scaled Linear Drag Calculation

	Vec3 ScaledLinearDrag;
	ScaledLinearDrag.x = m_LinearVelocity.x * m_LinearDrag.x * a_DeltaTime;
	ScaledLinearDrag.y = m_LinearVelocity.y * m_LinearDrag.y * a_DeltaTime;

	#pragma endregion
	m_LinearVelocity = Vector3Subtract( m_LinearVelocity, ScaledLinearDrag ); // Subtracts the Drag
	m_AttachedObjectTransform->AddLocalPosition( Vector3Scale(m_LinearVelocity, a_DeltaTime) ); // Update the Transforms Position

	// ===== Angular Movement =====
	m_AngularVelocity += m_AngularAcceleration * a_DeltaTime;
	m_AngularVelocity -= m_AngularDrag * m_AngularVelocity * a_DeltaTime;
	m_AttachedObjectTransform->AddLocalRotation( m_AngularVelocity * a_DeltaTime );
}

void RigidBody2D::Draw()
{
}

void RigidBody2D::SetUpComponent()
{
	m_AttachedObjectTransform = &m_AttachedObject->GetTransform();
}

void RigidBody2D::SetLinearAcceleration(float a_LinearSpeed)
{
	m_LinearAcceleration = Vector3Scale( 
		Vector3Normalize(Vec3{ m_AttachedObjectTransform->GetGlobalMatrix().m0, m_AttachedObjectTransform->GetGlobalMatrix().m4 }), // Finds the Normal of the Direction the Transform is facing
		a_LinearSpeed);
}

void RigidBody2D::SetLinearVelocity(float a_LinearSpeed)
{
	m_LinearSpeed = a_LinearSpeed;
	m_LinearVelocity = Vector3Scale(
		Vector3Normalize(Vec3{ m_AttachedObjectTransform->GetGlobalMatrix().m0, m_AttachedObjectTransform->GetGlobalMatrix().m4 }), // Finds the Normal of the Direction the Transform is facing
		a_LinearSpeed);
}
