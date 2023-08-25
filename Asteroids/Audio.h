#pragma once
#include "Resource.h"
#include "raylib.h"

class Audio :
    public Resource
{
public:
    Audio() = default;
    Audio(const char* FilePath);
    ~Audio();
    
    Sound* GetSound() { return &m_Sound; }

    // ===== Load Handling =====
    virtual bool Load(const char* a_FilePath) override;
    virtual bool Unload() override;
    virtual bool IsLoaded() override;

private:
    Sound m_Sound = Sound();
};

