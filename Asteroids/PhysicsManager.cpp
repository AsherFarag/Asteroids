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

void PhysicsManager::UnregisterCollider(CircleCollider2D* a_Collider)
{
	m_CircleColliders.erase( std::remove(m_CircleColliders.begin(), m_CircleColliders.end(), a_Collider) );
}

void PhysicsManager::CheckForCollisions()
{
	for (int i = 0; i < m_CircleColliders.size(); i++)
	{
		CircleCollider2D* Collider = m_CircleColliders[i];

		if (*Collider->GetTag() == "SpaceCraft" || *Collider->GetTag() == "Bullet") // If the Collider is a SpaceCraft or a Bullet
		{
			if (CheckIfCollidingWithAsteroid(Collider)) // If the Collider is Colliding with an Asteroid
			{
				Collider->OnTrigger();
			}
		}
	}
}

bool PhysicsManager::CheckIfCollidingWithAsteroid(CircleCollider2D* a_Collider)
{
	for (int i = 0; i < m_CircleColliders.size(); i++ )
	{
		CircleCollider2D* Asteroid = m_CircleColliders[i];

		if (*Asteroid->GetTag() == "Asteroid" && &Asteroid != &a_Collider)
		{
			Vec3 ColliderPos = a_Collider->GetTransform()->GetLocalPosition();
			Vec3 AsteroidPos = Asteroid->GetTransform()->GetLocalPosition();

			//  Hypotenuse =							     X squared                         +                                 Y Squared	
			float Distance = (ColliderPos.x - AsteroidPos.x) * (ColliderPos.x - AsteroidPos.x) + (ColliderPos.y - AsteroidPos.y) * (ColliderPos.y - AsteroidPos.y); // Finds the Squared Distance between the two Colliders

			// Checks if the Distance between the two Colliders is Less than their Radiuses Combined
			bool IsColliding = sqrtf(Distance) < (a_Collider->GetRadius() + Asteroid->GetRadius());

			if (IsColliding)
			{
				Asteroid->OnTrigger();
				return true;
			}
		}
	}

	return false;
}
