#pragma once
#include "Resource.h"
#include "raylib.h"
class Sprite2D :
    public Resource
{
public:
    Sprite2D(const char*);
    ~Sprite2D();

    // ===== Load Handling =====
    virtual bool Load(const char* a_FilePath) override;
    virtual bool Unload() override;
    virtual bool IsLoaded() override;

    Image* GetImage() { return &m_Image; }
    Texture2D* GetTexture();
    int GetTextureWidth()  { return m_Texture2D.width; }
    int GetTextureHeight() { return m_Texture2D.height; }

private:
    Image m_Image;
    Texture2D m_Texture2D;
};

