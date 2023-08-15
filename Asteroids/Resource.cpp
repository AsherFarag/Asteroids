#include "Resource.h"
#include "Sprite2D.h"
#include "Audio.h"
#include "raylib.h"
#include <typeinfo>

#pragma region Static Members

map< size_t, map< string, Resource*> > Resource::s_Resources;

void Resource::LoadResources()
{
	int FileCount = 0;
	char** FilePaths = GetDirectoryFiles(RESOURCE_LOCATION, &FileCount);

	for (int i = 0; i < FileCount; i++)
	{
		string FilePath = FilePaths[i];

		if (FilePath == "." || FilePath == "..")
			continue;

		FilePath = RESOURCE_LOCATION +  string("/") + FilePath;

		string FileExtension = GetExtension(FilePath.c_str());
		string FileName = GetFileNameWithoutExt(FilePath.c_str());

		if (FileExtension == "png") // ===== Image Loading =====
		{
			auto& Type = typeid(Sprite2D);
			auto TypeHash = Type.hash_code();
			Resource* TextureAddress = new Sprite2D(FilePath.c_str());
			s_Resources[TypeHash][FileName] = TextureAddress;
		}
		else if (FileExtension == "wav") // ===== Sound Loading =====
		{
			auto& Type = typeid(Audio);
			auto TypeHash = Type.hash_code();
			Resource* AudioAddress = new Audio(FilePath.c_str());
			s_Resources[TypeHash][FileName] = AudioAddress;
		}
	}

	free(FilePaths);
}

void Resource::UnloadResources()
{
	for (auto& ResourceMap : s_Resources)
	{
		for (auto& Resource : ResourceMap.second)
		{
			delete Resource.second;
		}
	}

	s_Resources.clear();
}

#pragma endregion