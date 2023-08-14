#include "GameObject.h"
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

	m_GameObjects = new GameObject[m_GameObjectsSize]; // Initialises the GameObject array to a set size
}

void EngineAPI::Run()
{
	
	while (!WindowShouldClose())
	{
		float DeltaTime = GetFrameTime();
		Update(DeltaTime);
		Draw();
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

void EngineAPI::RegisterGameObject(GameObject a_GameObject)
{
	if (m_ElementsInGameObjects == m_GameObjectsSize)
	{
		m_GameObjectsSize *= 2;
		m_GameObjects = new GameObject[m_GameObjectsSize];
	}

}

void EngineAPI::UnregisterGameObject(GameObject a_GameObject)
{

}

void EngineAPI::Update(float a_DeltaTime)
{

}

void EngineAPI::Draw()
{

}

#pragma endregion