#pragma once

#include <map>
#include <string>

using std::map;
using std::string;

class Resource
{
public:
#pragma region Static Members
	static map<string, Resource*> s_Resources;
#pragma endregion

};

