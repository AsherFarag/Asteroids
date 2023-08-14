#pragma once
#include "raylib.h"

class GameObject;

class EngineAPI
{
public:
#pragma region Singleton

	static EngineAPI* GetInstance();
	EngineAPI(EngineAPI& other) = delete;
	void operator=(const EngineAPI&) = delete;
#pragma endregion
	// ===== Game States =====
	void Start();
	void Run();
	void End();

	// ===== Properties =====
	const int GetWindowWidth();
	const int GetWindowHeight();

protected:
private:
	EngineAPI();
	~EngineAPI();

	static EngineAPI* m_Instance;

	void Load();
	void Unload();

	void RegisterGameObject(GameObject a_GameObject);	// Adds the GameObject to the dynamic array
	void UnregisterGameObject(GameObject a_GameObject); // Removes the GameObject from the dynamic array

	void Update(float a_DeltaTime);
	void Draw();

	const char* m_ApplicationName = "Asteroids";

	const int m_TargetFPS	   = 60;

	const int m_WindowWidth  = 800;
	const int m_WindowHeight = 800;

	const int m_WindowScaleX = 1;
	const int m_WindowScaleY = 1;

	GameObject* m_GameObjects = nullptr;
	int m_GameObjectsSize = 50;
	int m_ElementsInGameObjects = 0;
};