#pragma once

#include <map>
#include <vector>
#include <typeinfo>
#include "Transformation.h"
#include "Component.h"

class GameObject
{
public:
	GameObject();
	GameObject(GameObject* a_Parent);
	~GameObject();
	
	Transformation& GetTransform() { return m_Transform; }

	#pragma region Heirarchy Handling

	GameObject* m_Parent = nullptr;
	std::vector<GameObject*> m_Children;
	std::map<size_t, Component*> m_Components;

	void AddChild(GameObject* a_Child);

	template < typename T >
	T* AddComponent();

	template < typename T >
	T* GetComponent();

	template < typename T >
	bool DestroyComponent();

	#pragma endregion

	void Update(float a_DeltaTime);
	void Draw();

protected:
	Transformation m_Transform;
};

#pragma region Component Handling

template < typename T >
T* GameObject::AddComponent()
{
	auto& Type = typeid(T);
	auto TypeHash = Type.hash_code();
	Component*& NewComponent = m_Components[TypeHash];

	if (NewComponent != nullptr)
	{
		return (T*)NewComponent;
	}

	NewComponent = new T();
	NewComponent->m_AttachedObject = this;
	NewComponent->SetUpComponent();
	return (T*)NewComponent;
}

template < typename T >
T* GameObject::GetComponent()
{
	auto& Type = typeid(T);
	auto TypeHash = Type.hash_code();
	return (T*)m_Components[TypeHash];
}

template < typename T >
bool GameObject::DestroyComponent()
{
	auto& Type = typeid(T);
	auto TypeHash = Type.hash_code();
	Component* ToDestroy = m_Components[TypeHash];

	if (ToDestroy == nullptr)
	{
		return false;
	}

	delete ToDestroy;
	return true;
}

#pragma endregion