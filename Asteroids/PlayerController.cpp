#include "PlayerController.h"
#include "raylib.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Audio.h"

void PlayerController::Update(float a_DeltaTime)
{
	#pragma region Movement Input

	// ===== Linear Movement =====
	if (IsKeyDown(KEY_W))
	{
		m_AttachedObjectRB->SetLinearAcceleration(1500.0f);

		if (!IsSoundPlaying(*Resource::GetResource<Audio>("thrust")->GetSound()))
		{
			PlaySound(*Resource::GetResource<Audio>("thrust")->GetSound());
		}	

		m_AttachedObject->GetComponent<SpriteRenderer>()->SetSprite("SpaceCraftThruster", 0.5f, 0.5f);
		
	}

	if (IsKeyReleased(KEY_W))
	{
		m_AttachedObjectRB->SetLinearAcceleration(Vector3Zero());
		StopSound(*Resource::GetResource<Audio>("thrust")->GetSound());
		m_AttachedObject->GetComponent<SpriteRenderer>()->SetSprite("SpaceCraft", 0.5f, 0.5f);
	}

	// ===== Angular Movement =====
	if (IsKeyDown(KEY_A))
	{
		m_AttachedObjectRB->SetAngularVelocity(3.0f);
	}

	if (IsKeyDown(KEY_D))
	{
		m_AttachedObjectRB->SetAngularVelocity(-3.0f);
	}

	#pragma endregion

	#pragma region Weapon Input

	if (IsKeyPressed(KEY_SPACE))
	{
		new Bullet(m_AttachedObjectTransform, 500);
		PlaySound(*Resource::GetResource<Audio>("fire")->GetSound());
	}

	#pragma endregion

}

void PlayerController::Draw()
{

}

void PlayerController::SetUpComponent()
{
	m_AttachedObjectRB = m_AttachedObject->GetComponent<RigidBody2D>();
	m_AttachedObjectTransform = &m_AttachedObject->GetTransform();
}
