#pragma once
#include "GameObject.h"
#include "EngineAPI.h"
#include "SpriteRenderer.h"
#include "RigidBody2D.h"

class Asteroid :
    public GameObject
{
public:
    Asteroid(int a_Size); // Base Constructor
    Asteroid(int a_Size, Transformation* a_CopyTransformation); // Called when an Asteroid is Destroyed and Smaller ones are created
    Asteroid(int a_Size, Vec3 a_SpawnPosition, float a_Rotation, float a_Speed); // Called when a New Asteroid is being made by the Game Manager
    ~Asteroid();

private:
    // ===== Components =====
    RigidBody2D* m_RigidBody2D;
    SpriteRenderer* m_SpriteRenderer;

    int m_Size; // 3 = Small, 2 = Medium, 1 = Large
};

