#pragma once
#include "Component.h"
#include "GameObject.h"

class CircleCollider2D :
    public Component
{
public:
    CircleCollider2D();
    CircleCollider2D(float a_Radius);
    ~CircleCollider2D();

    virtual void SetUpComponent() override;

    virtual void Update(float a_DeltaTime) override;
    virtual void Draw() override { }
    void OnTrigger();

    std::string* GetTag() { return &m_Tag; }
    float   GetRadius() { return m_Radius; }
    void    SetRadius(float a_Value) { m_Radius = a_Value; }

    bool m_IsColliding = false;

    Transformation* GetTransform() { return m_AttachedTransform; }

private:
    std::string m_Tag;
    float m_Radius;
    Transformation* m_AttachedTransform;

};

