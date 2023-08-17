
#include "EngineAPI.h"
#include "SpaceCraft.h"
#include "Asteroid.h"

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
		//	Display Score:          Pos   Colour   Font
		m_GameManager.DisplayScore(10, 5, SKYBLUE, 50);

		// ===== FPS Counter =====
		std::string FPS = "FPS: " + std::to_string(GetFPS());
		DrawText(FPS.c_str(), 5, m_WindowHeight - 20, 20, SKYBLUE);

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

GameManager* EngineAPI::GetGameManager()
{
	if (GetInstance() == nullptr)
		return nullptr;

	return &m_Instance->m_GameManager;
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
	std::remove(m_GameObjects.begin(), m_GameObjects.end(), a_GameObject);
}

void EngineAPI::Update(float a_DeltaTime)
{
	for (int i = m_GameObjects.size() - 1; i >= 0; i--)
		m_GameObjects[i]->Update(a_DeltaTime);

	m_GameManager.Update(a_DeltaTime);
}

void EngineAPI::Draw()
{
	for (int i = m_GameObjects.size() - 1; i >= 0; i--)
		m_GameObjects[i]->Draw();
}

#pragma endregion