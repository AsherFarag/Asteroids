
#include "EngineAPI.h"
#include "SpaceCraft.h"

#pragma region Singleton Handling

EngineAPI* EngineAPI::m_Instance = nullptr;

EngineAPI* EngineAPI::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new EngineAPI();
	}
	return m_Instance;
}

#pragma endregion

#pragma region Game States

void EngineAPI::Start()
{
	InitWindow(m_WindowWidth, m_WindowHeight, m_ApplicationName);
	SetTargetFPS(m_TargetFPS);

	Load();
}

void EngineAPI::Run()
{
	SpaceCraft S; // Temp

	while (!WindowShouldClose())
	{
		float DeltaTime = GetFrameTime();

		Update(DeltaTime);

		#pragma region Graphics

		BeginDrawing();
		ClearBackground(BLACK);

		Draw();

		EndDrawing();

		#pragma endregion

		#pragma region User Interface
		m_GameManager.DisplayScore(10, 5, SKYBLUE, 50);
		#pragma endregion

	}
}

void EngineAPI::End()
{
	Unload();
	delete m_Instance;
}

#pragma endregion

#pragma region Getters

int EngineAPI::GetWindowWidth()
{
	return m_Instance->m_WindowWidth;
}
int EngineAPI::GetWindowHeight()
{
	return m_Instance->m_WindowHeight;
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

#pragma region Resource Load Handling

void EngineAPI::Load()
{
	Resource::LoadResources();
}

void EngineAPI::Unload()
{
	Resource::UnloadResources();
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