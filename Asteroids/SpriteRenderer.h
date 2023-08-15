#pragma once
#include "Component.h"
#include "Sprite2D.h"
#include "GameObject.h"
#include "EngineAPI.h"
#include "Transformation.h"
#include <raylib.h>

class SpriteRenderer :
    public Component
{
public:
    SpriteRenderer();
    ~SpriteRenderer();

    Color m_Tint = RAYLIB_H::WHITE;

    float m_PivotSpawnX, m_PivotSpawnY; // On Load, these Numbers are used to Spawn the Pivot at a Point Set by the Attached Object
    Vector2 m_Pivot; // Where the Sprite is Connected to and Rotates Around

    virtual void Update(float a_DeltaTime) override;
    virtual void Draw() override;

    void SetSprite(const string& a_SpriteName);

private:
    Sprite2D* m_Texture;
    Rectangle m_TextureMask;
};

