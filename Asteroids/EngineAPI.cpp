
#include "EngineAPI.h"

EngineAPI* EngineAPI::m_Instance = nullptr;

EngineAPI* EngineAPI::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new EngineAPI();
	}
	return m_Instance;
}

#pragma region Game States

void EngineAPI::Start()
{
	InitWindow(m_WindowWidth, m_WindowHeight, m_ApplicationName);
	SetTargetFPS(m_TargetFPS);
}

void EngineAPI::Run()
{
	
	while (!WindowShouldClose())
	{
		float DeltaTime = GetFrameTime();

		Update(DeltaTime);

		#pragma region Graphics
		BeginDrawing();
		ClearBackground(BLACK);

		Draw();

		// ===== Temp =====
		DrawText("20!", 350, 350, 50, GREEN);

		EndDrawing();
		#pragma endregion
	}
}

void EngineAPI::End()
{
	delete m_Instance;
}

#pragma endregion




#pragma region Properties

const int EngineAPI::GetWindowWidth()
{
	return m_WindowWidth;
}
const int EngineAPI::GetWindowHeight()
{
	return m_WindowHeight;
}

#pragma endregion

#pragma region Constructors

EngineAPI::EngineAPI()
{

}

EngineAPI::~EngineAPI()
{

}

#pragma endregion

#pragma region Load Handling

void EngineAPI::Load()
{

}

void EngineAPI::Unload()
{

}

#pragma endregion

#pragma region GameObject Handling

void EngineAPI::RegisterGameObject(GameObject* a_GameObject)
{
	m_GameObjects.push_back(a_GameObject);
}

void EngineAPI::UnregisterGameObject(GameObject* a_GameObject)
{
	for (int i = 0; i < m_GameObjects.size(); i++)
		m_GameObjects.at(i) = nullptr;
}

void EngineAPI::Update(float a_DeltaTime)
{
	for (int i = 0; i < m_GameObjects.size(); i++)
		m_GameObjects.at(i)->Update(a_DeltaTime);
}

void EngineAPI::Draw()
{
	for (int i = 0; i < m_GameObjects.size(); i++)
		m_GameObjects.at(i)->Draw();
}

#pragma endregion