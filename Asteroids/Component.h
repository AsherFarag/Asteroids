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

protected:
private:
	
};

