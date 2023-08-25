#pragma once
#include "GameObject.h"
#include "EngineAPI.h"
#include "SpriteRenderer.h"
#include "RigidBody2D.h"
#include "CircleCollider2D.h"

class Asteroid :
    public GameObject
{
public:
    Asteroid(int a_Size); // Base Constructor
    Asteroid(int a_Size, Transformation* a_CopyTransformation); // Called when an Asteroid is Destroyed and Smaller ones are created
    Asteroid(int a_Size, Vec3 a_SpawnPosition, float a_Rotation, float a_Speed); // Called when a New Asteroid is being made by the Game Manager
    ~Asteroid();

    virtual void Update(float a_DeltaTime) override;
    virtual void Destroy() override;

private:
    // ===== Components =====
    RigidBody2D* m_RigidBody2D;
    CircleCollider2D* m_CircleCollider2D;
    SpriteRenderer* m_SpriteRenderer;

    void SpawnSmallerAsteroids(int a_Size);

    int m_Size; // 3 = Small, 2 = Medium, 1 = Large
};

