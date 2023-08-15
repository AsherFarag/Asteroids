#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "Resource.h"
#include <vector>

class GameObject;

class EngineAPI
{
public:
#pragma region Singleton_Handling

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

	// ===== GameObject Handling =====
	void RegisterGameObject(GameObject* a_GameObject);	// Adds the GameObject to the dynamic array
	void UnregisterGameObject(GameObject* a_GameObject); // Removes the GameObject from the dynamic array

private:
	EngineAPI();
	~EngineAPI();

	static EngineAPI* m_Instance; // Singleton Instance

	void Load(); // Load Resources at Start
	void Unload(); // Unload Resources at End

	void Update(float a_DeltaTime); // Iterates through m_GameObjects and calls Update on each Game Object
	void Draw();

	const char* m_ApplicationName = "Asteroids";

	const int m_TargetFPS	   = 60;

	const int m_WindowWidth  = 800;
	const int m_WindowHeight = 800;

	const int m_WindowScaleX = 1;
	const int m_WindowScaleY = 1;

	std::vector<GameObject*> m_GameObjects;

	/*GameObject* m_GameObjects = nullptr;
	int m_GameObjectsSize = 50;
	int m_ElementsInGameObjects = 0;*/
};