#pragma once

#define RESOURCE_LOCATION "../Resources"

#include <map>
#include <string>

using std::map;
using std::string;


enum class ResourceType
{
	Texture2D,
	Sound,
};


class Resource
{
public:
	Resource() = default;
	virtual ~Resource() = default;

	static map< size_t, map<string, Resource*> > s_Resources;
	
	#pragma region Load Handling

	static void LoadResources();
	static void UnloadResources();

	virtual bool Load(const char* a_FilePath) = 0;
	virtual bool IsLoaded() = 0;
	virtual bool Unload() = 0;

	#pragma endregion

	// ===== Getters =====
	template < typename T >
	static T* GetResource(const string& a_ResourceName)
	{
		auto& Type = typeid(T);
		auto TypeHash = Type.hash_code();

		auto MapIterator = s_Resources.find(TypeHash);
		if (MapIterator == s_Resources.end())
		{
			return nullptr;
		}
		
		auto ResourceIterrator = MapIterator->second.find(a_ResourceName);
		if (ResourceIterrator == MapIterator->second.end())
		{
			return nullptr;
		}

		return (T*)ResourceIterrator->second;
	}
};

