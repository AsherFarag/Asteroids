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

    virtual void Update(float a_DeltaTime) override;
    virtual void Draw() override;

    void SetSprite(const string& a_SpriteName, float a_PivotSpawnX, float a_PivotSpawnY);

private:
    Sprite2D* m_Sprite2D;
    Vector2 m_Pivot; // Where the Sprite is Connected to and Rotates Around
    Rectangle m_TextureMask;
};

