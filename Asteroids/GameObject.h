#pragma once

#include <vector>
#include "Transform.h"

class Component;
class Transformation;

class GameObject
{
public:

	GameObject();
	GameObject(GameObject* a_Parent);
	~GameObject();
	
	Transformation& GetTransform() { return m_Transform; }

	GameObject* m_Parent = nullptr;
	std::vector<GameObject*> m_Children;
	std::vector<Component*> m_Components;

	void AddChild(GameObject* a_Child);
	void AddComponent(Component* a_Component);

	void Update(float* a_DeltaTime);
	void Draw();

private:

	Transformation m_Transform;
};