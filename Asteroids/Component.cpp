#include "Component.h"

Component::Component(GameObject* a_AttachedObject)
{
	m_AttachedObject = a_AttachedObject;
}

Component::~Component()
{

}

void Component::Draw()
{
}
