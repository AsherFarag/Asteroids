#pragma once
#include <vector>
#include "CircleCollider2D.h"

class PhysicsManager
{
#pragma region Collison Management

	std::vector<CircleCollider2D*> m_CircleColliders;

public:
	void FixedUpdate(float a_DeltaTime);
	void RegisterCollider(CircleCollider2D* a_Collider);

private:
	float m_FrameTime = 0.0f; // For Fixed Update

	void CheckForCollisions();
	bool CheckIfCollidingWithAsteroid(CircleCollider2D* a_Collider);
	

#pragma endregion

};

