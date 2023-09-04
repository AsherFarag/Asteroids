
#include "EngineAPI.h"
#include "SpaceCraft.h"
#include "Asteroid.h"
#include "Audio.h"

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

	InitAudioDevice();

	Load();

	SetWindowIcon(*Resource::GetResource<Sprite2D>("LargeAsteroid1")->GetImage());

	new SpaceCraft();
}

void EngineAPI::Run()
{
	while (!WindowShouldClose())
	{
		#pragma region Music

		if (!IsSoundPlaying(*Resource::GetResource<Audio>("IntoTheVoid3")->GetSound()))
		{
			PlaySound(*Resource::GetResource<Audio>("IntoTheVoid3")->GetSound());
			SetSoundVolume(*Resource::GetResource<Audio>("IntoTheVoid3")->GetSound(), 0.3f);
		}

		#pragma endregion

		float DeltaTime = GetFrameTime();

		Update(DeltaTime);

		#pragma region Graphics

		BeginDrawing();

		ClearBackground(BLACK);

		Draw();

		#pragma region User Interface
		// Display Score:            Pos  Colour  Font
		m_GameManager.DisplayScore(10, 5, SKYBLUE, 50);
		// Display Player Lives:      Pos  Colour  Font
		m_GameManager.DisplayLives(10, 50, SKYBLUE, 50);
		// Display Game Over Screen IF it is Game Over
		if (m_GameManager.m_GameOver)
		{
			m_GameManager.DisplayDeathScreen();
			m_GameManager.DisplayRestartButton();
		}

		// ===== FPS Counter =====
		std::string FPS = "FPS: " + std::to_string(GetFPS());
		DrawText(FPS.c_str(), 5, m_WindowHeight - 20, 20, SKYBLUE);

		#pragma endregion

		EndDrawing();

		#pragma endregion
	}
}

void EngineAPI::End()
{
	Unload();
	CloseAudioDevice();
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

int EngineAPI::GetTargetFrameRate()
{
	return m_Instance->m_TargetFPS;
}

GameManager* EngineAPI::GetGameManager()
{
	if (GetInstance() == nullptr)
		return nullptr;

	return &m_Instance->m_GameManager;
}

PhysicsManager* EngineAPI::GetPhysicsManager()
{
	if (GetInstance() == nullptr)
		return nullptr;

	return &m_Instance->m_PhysicsManager;
}

#pragma endregion

#pragma region Constructors

EngineAPI::EngineAPI()
{

}

EngineAPI::~EngineAPI()
{
	ClearGameObjects();
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

void EngineAPI::ClearGameObjects()
{
	auto Temp = m_Instance->m_GameObjects;
	for (auto GameObject : Temp)
	{
		delete GameObject;
	}
	m_Instance->m_GameObjects.clear();

	auto TempPhys = m_Instance->GetPhysicsManager()->m_CircleColliders;
	for (auto Collider : TempPhys)
	{
		delete Collider;
	}
	m_Instance->GetPhysicsManager()->m_CircleColliders.clear();
}

void EngineAPI::RegisterGameObject(GameObject* a_GameObject)
{
	m_Instance->m_GameObjects.push_back(a_GameObject);
}

void EngineAPI::UnregisterGameObject(GameObject* a_GameObject)
{
	m_Instance->m_GameObjects.erase( std::remove(m_Instance->m_GameObjects.begin(), m_Instance->m_GameObjects.end(), a_GameObject) );
}

void EngineAPI::Update(float a_DeltaTime)
{
	for (int i = m_GameObjects.size() - 1; i >= 0; i--)
	{
		m_GameObjects[i]->Update(a_DeltaTime);
	}

	m_GameManager.Update(a_DeltaTime);
	m_PhysicsManager.FixedUpdate(a_DeltaTime);
}

void EngineAPI::Draw()
{
	for (int i = m_GameObjects.size() - 1; i >= 0; i--)
		m_GameObjects[i]->Draw();
}

#pragma endregion