#pragma once
#include <vector>
#include "CircleCollider2D.h"

class PhysicsManager
{
#pragma region Collison Management
public:
	std::vector<CircleCollider2D*> m_CircleColliders;

	void FixedUpdate(float a_DeltaTime);
	void RegisterCollider(CircleCollider2D* a_Collider);
	void UnregisterCollider(CircleCollider2D* a_Collider);

private:
	float m_FrameTime = 0.0f; // For Fixed Update

	void CheckForCollisions();
	bool CheckIfCollidingWithAsteroid(CircleCollider2D* a_Collider);
	

#pragma endregion

};

