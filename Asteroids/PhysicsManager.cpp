#include "PhysicsManager.h"
#include "EngineAPI.h"

void PhysicsManager::FixedUpdate(float a_DeltaTime)
{
	m_FrameTime += a_DeltaTime;

	if ( m_FrameTime >= (1.0f / EngineAPI::GetTargetFrameRate()) ) // Only Updates at a Fixed Rate
	{
		CheckForCollisions();
	}
}

void PhysicsManager::RegisterCollider(CircleCollider2D* a_Collider)
{
	m_CircleColliders.push_back(a_Collider);
}

void PhysicsManager::CheckForCollisions()
{
	for (auto Collider : m_CircleColliders)
	{
		if (*Collider->GetTag() == "SpaceCraft")
		{
			if (CheckIfCollidingWithAsteroid(Collider))
			{
				Collider->m_IsColliding = true;
				std::cout << " ====================== Is Colliding! ====================== \n";
				//delete Collider->m_AttachedObject;

			}
		}
	}
}

bool PhysicsManager::CheckIfCollidingWithAsteroid(CircleCollider2D* a_Collider)
{
	for (auto Asteroid : m_CircleColliders)
	{
		if (*Asteroid->GetTag() == "Asteroid" && &Asteroid != &a_Collider)
		{
			Vec3 ColliderPos = a_Collider->GetTransform()->GetLocalPosition();
			Vec3 AsteroidPos = Asteroid->GetTransform()->GetLocalPosition();

			//  Hypotenuse =							     X squared                         +                                 Y Squared	
			float Distance = (ColliderPos.x - AsteroidPos.x) * (ColliderPos.x - AsteroidPos.x) + (ColliderPos.y - AsteroidPos.y) * (ColliderPos.y - AsteroidPos.y); // Finds the Squared Distance between the two Colliders

			bool IsColliding = sqrtf(Distance) < (a_Collider->GetRadius() + Asteroid->GetRadius()); // Checks if the Distance between the two Colliders is Less than their Radiuses Combined

			if (IsColliding)
			{
				m_CircleColliders.erase( std::remove(m_CircleColliders.begin(), m_CircleColliders.end(), Asteroid) );
				Asteroid->m_AttachedObject->Destroy();
				return true;
			}
		}
	}

	return false;
}
