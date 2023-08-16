#include "PlayerController.h"
#include "raylib.h"
#include "GameObject.h"

void PlayerController::Update(float a_DeltaTime)
{
	#pragma region Movement Input

	// ===== Linear Movement =====
	if (IsKeyDown(KeyboardKey(KEY_W)))
	{
		m_AttachedObjectRB->SetLinearAcceleration(1500.0f);
	}
	if (IsKeyReleased(KeyboardKey(KEY_W)))
	{
		m_AttachedObjectRB->SetLinearAcceleration(Vector3Zero());
	}

	// ===== Angular Movement =====
	if (IsKeyDown(KeyboardKey(KEY_A)))
	{
		m_AttachedObjectRB->SetAngularVelocity(3.0f);
	}
	if (IsKeyDown(KeyboardKey(KEY_D)))
	{
		m_AttachedObjectRB->SetAngularVelocity(-3.0f);
	}

	#pragma endregion

	
}

void PlayerController::Draw()
{
}

void PlayerController::SetUpComponent()
{
	m_AttachedObjectRB = m_AttachedObject->GetComponent<RigidBody2D>();
}
