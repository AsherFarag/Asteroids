#pragma once

class GameObject;

class Component
{
public:
	Component();
	~Component();

	GameObject* m_AttachedObject;

	virtual void Update(float a_DeltaTime) = 0;
	virtual void Draw() = 0;
	virtual void Destroy() { delete this; }

	virtual void SetUpComponent() = 0; // Called at the End of GameObject::AddComponent once the Component has a Parent

protected:
private:
	
};

