#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer() : Component() {}

SpriteRenderer::~SpriteRenderer() {}

void SpriteRenderer::SetSprite(const string& a_SpriteName)
{
	m_Texture = Resource::GetResource<Sprite2D>(a_SpriteName);
	if (m_Texture == nullptr)
	{
		m_TextureMask = Rectangle{ 0.0f, 0.0f, 0.0f, 0.0f }; // Default Mask
		return;
	}

	m_TextureMask = Rectangle{ 0.0f, 0.0f, (float)m_Texture->GetTextureWidth(), (float)m_Texture->GetTextureHeight() };
}

void SpriteRenderer::Update(float a_DeltaTime) { }

void SpriteRenderer::Draw()
{
	if (m_Texture == nullptr)
		return;

	Vector3 Position = m_AttachedObject->GetTransform().GetGlobalPosition();
	float Rotation = m_AttachedObject->GetTransform().GetGlobalRotation();

	RAYLIB_H::DrawTexturePro(
		*m_Texture->GetTexture(),// The Texture that is being Rendered
		m_TextureMask, // Rectangle set to the Size of the Sprite 
		Rectangle{ Position.x, EngineAPI::GetInstance()->GetWindowHeight() - Position.y, (float)m_Texture->GetTextureWidth(), (float)m_Texture->GetTextureHeight()}, // Where the Sprite is Drawn in the World
		m_Pivot,	   // A point where the Sprite is Drawn and Rotated around
		Rotation,	   // The Global Rotation of the Sprite
		m_Tint);	   // the Colour of the Sprite
}

