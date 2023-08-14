#include "SpriteRenderer.h"
#include "GameObject.h"
#include <raylib.h>
#include "EngineAPI.h"

float SpriteRenderer::GetTextureWidth()
{
	return m_Texture.width;
}
float SpriteRenderer::GetTextureHeight()
{
	return m_Texture.height;
}

void SpriteRenderer::Update(float* a_DeltaTime)
{
}

void SpriteRenderer::Draw()
{
	Vector3 Position = m_AttachedObject->GetTransform()->GetGlobalPosition();
	float Rotation = m_AttachedObject->GetTransform()->GetGlobalRotation() * (float)(180.0f / PI);

	RAYLIB_H::DrawTexturePro(
		m_Texture,	   // The Texture that is being Rendered
		m_TextureMask, // Rectangle set to the Size of the Sprite 
		Rectangle{ Position.x, EngineAPI::GetInstance()->GetWindowHeight() - Position.y, GetTextureWidth(), GetTextureHeight()}, // Where the Sprite is Drawn in the World
		m_Pivot,	   // A point where the Sprite is Drawn and Rotated around
		Rotation,	   // The Global Rotation of the Sprite
		m_Tint);	   // the Colour of the Sprite
}