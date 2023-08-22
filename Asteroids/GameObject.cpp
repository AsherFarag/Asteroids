#include "GameObject.h"
#include "Component.h"
#include "Transformation.h"
#include "EngineAPI.h"
#include "SpriteRenderer.h"

// ===== Constructors =====
GameObject::GameObject()
{
	m_Transform = Transformation(); // Creates a Transformation
	EngineAPI::GetInstance()->RegisterGameObject(this); // Registers this GameObject to the Engine Instance
}

GameObject::GameObject(GameObject* a_Parent)
{
	m_Transform = Transformation(); // Creates a Transformation
	EngineAPI::GetInstance()->RegisterGameObject(this); // Registers this GameObject to the Engine Instance

	m_Parent = a_Parent;
	m_Parent->AddChild(this);
}

GameObject::~GameObject()
{
	EngineAPI::UnregisterGameObject(this); // Unregisters this GameObject from the Engine Instance
	for (auto Pair : m_Components)
	{
		delete Pair.second;
	}
}

// ===== Heirarchy Handling =====
void GameObject::AddChild(GameObject* a_Child)
{
	m_Children.push_back(a_Child);
	a_Child->GetTransform().m_Parent = &m_Transform;
}



void GameObject::Update(float a_DeltaTime)
{
	for (auto Comp : m_Components)
	{
		Comp.second->Update(a_DeltaTime);
	}
}

void GameObject::Draw()
{
	if (SpriteRenderer* SR = GetComponent<SpriteRenderer>())
	{
		SR->Draw();
	}
}