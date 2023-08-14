#include "GameObject.h"
#include "Component.h"
#include "Transformation.h"

GameObject::GameObject()
{
	m_Transform = Transformation();
}
GameObject::GameObject(GameObject* a_Parent)
{
	GameObject();
	m_Parent = a_Parent;
	m_Parent->AddChild(this);
}
GameObject::~GameObject()
{
	for (int i = 0; i < m_Components.size(); i++)
	{
		m_Components[i] = nullptr;
		delete m_Components[i];
	}
}

void GameObject::AddChild(GameObject* a_Child)
{
	m_Children.push_back(a_Child);
	a_Child->GetTransform().m_Parent = &m_Transform;
}
void GameObject::AddComponent(Component* a_Component)
{
	m_Components.push_back(a_Component);
}

void GameObject::Update(float* a_DeltaTime)
{

}

void GameObject::Draw()
{

}