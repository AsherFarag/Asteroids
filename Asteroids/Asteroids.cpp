
#include <iostream>
#include "EngineAPI.h"

int main()
{
	EngineAPI::GetInstance()->Start();
	EngineAPI::GetInstance()->Run();
	EngineAPI::GetInstance()->End();
	return 0;
}
