#include "Audio.h"

Audio::Audio(const char* a_FilePath)
{
	Load(a_FilePath);
}

Audio::~Audio()
{
	if (IsLoaded())
		UnloadSound(m_Sound);
}

#pragma region Load Handling

bool Audio::Load(const char* a_FilePath)
{
	Unload();
	m_Sound = LoadSound(a_FilePath);
	return IsLoaded();
}

bool Audio::IsLoaded()
{
	return m_Sound.sampleCount != 0;
}

bool Audio::Unload()
{
	if (IsLoaded())
	{
		StopSound(m_Sound);
		UnloadSound(m_Sound);
		m_Sound = Sound();
		return true;
	}
	return false;
}

#pragma endregion

