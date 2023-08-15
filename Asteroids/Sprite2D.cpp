#include "Sprite2D.h"

Sprite2D::Sprite2D(const char* a_FilePath)
	: m_Texture2D()
{
	Load(a_FilePath);
}

Sprite2D::~Sprite2D()
{
	Unload();
}

#pragma region Load Handling

bool Sprite2D::Load(const char* a_FilePath)
{
	if (IsLoaded())
	{
		Unload();
	}

	m_Texture2D = LoadTexture(a_FilePath);
	return IsLoaded();
}

bool Sprite2D::IsLoaded()
{
	return m_Texture2D.id != 0u;
}

bool Sprite2D::Unload()
{
	if (IsLoaded())
	{
		UnloadTexture(m_Texture2D);
		m_Texture2D = Texture2D();
		return true;
	}
	return false;
}

Texture2D* Sprite2D::GetTexture()
{
	return &m_Texture2D;
}

#pragma endregion