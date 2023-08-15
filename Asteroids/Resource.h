#pragma once

#include <map>
#include <string>

using std::map;
using std::string;

class Resource
{
public:
	static map<string, Resource*> s_Resources;
};

