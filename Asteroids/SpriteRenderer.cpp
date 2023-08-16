#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer() : Component() {}

SpriteRenderer::~SpriteRenderer() {}

void SpriteRenderer::SetSprite(const string& a_SpriteName, float a_PivotSpawnX, float a_PivotSpawnY)
{
	m_Sprite2D = Resource::GetResource<Sprite2D>(a_SpriteName);

	if (m_Sprite2D == nullptr)
	{
		m_TextureMask = Rectangle{ 0.0f, 0.0f, 0.0f, 0.0f };
		return;
	}

	m_Pivot = Vec2{ (float)m_Sprite2D->GetTextureWidth() * a_PivotSpawnX, (float)m_Sprite2D->GetTextureHeight() * a_PivotSpawnY }; 

	m_TextureMask = Rectangle{ 0.0f, 0.0f, (float)m_Sprite2D->GetTextureWidth(), (float)m_Sprite2D->GetTextureHeight() };
}

void SpriteRenderer::Update(float a_DeltaTime) { }

void SpriteRenderer::Draw()
{
	if (m_Sprite2D == nullptr)
		return;

	Vector3 Position = m_AttachedObject->GetTransform().GetLocalPosition();
	float Rotation = m_AttachedObject->GetTransform().GetGlobalRotation() * (float)(180.0f / PI);

	RAYLIB_H::DrawTexturePro(
		*m_Sprite2D->GetTexture(),// The Texture that is being Rendered
		m_TextureMask, // Rectangle set to the Size of the Sprite 
		Rectangle{ Position.x, EngineAPI::GetInstance()->GetWindowHeight() - Position.y, (float)m_Sprite2D->GetTextureWidth(), (float)m_Sprite2D->GetTextureHeight()}, // Where the Sprite is Drawn in the World
		m_Pivot,	   // A point where the Sprite is Drawn and Rotated around
		Rotation,	   // The Global Rotation of the Sprite
		m_Tint);	   // the Colour of the Sprite
}

void SpriteRenderer::SetUpComponent()
{

}

