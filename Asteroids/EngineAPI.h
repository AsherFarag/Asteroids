#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "Resource.h"
#include <vector>
#include "GameManager.h"
#include "PhysicsManager.h"

class GameObject;

class EngineAPI
{
public:
	#pragma region Singleton_Handling

	EngineAPI(EngineAPI& other) = delete;
	void operator=(const EngineAPI&) = delete;

	#pragma endregion

	// ===== Game States =====
	void Start();
	void Run();
	void End();

	// ===== Getters =====
	static int   GetWindowWidth();
	static int   GetWindowHeight();
	static int   GetTargetFrameRate();
	static EngineAPI* GetInstance();
	static GameManager* GetGameManager();
	static PhysicsManager* GetPhysicsManager();

	// ===== GameObject Handling =====
	static void RegisterGameObject(GameObject* a_GameObject);	// Adds the GameObject to the List of GameObjects
	static void UnregisterGameObject(GameObject* a_GameObject); // Removes the GameObject from the List of GameObjects

	template < typename T, typename... Args >
	static T* InstantiateObject(Args ...a_Args);

private:
	EngineAPI();
	~EngineAPI();
	static EngineAPI* m_Instance; // Singleton Instance

	// ===== Managers =====
	GameManager m_GameManager;
	PhysicsManager m_PhysicsManager;

	void Load();   // Load Resources at Start
	void Unload(); // Unload Resources at End

	void Update(float a_DeltaTime); // Iterates through m_GameObjects and calls Update on each Game Object
	void Draw(); // Iterates through m_GameObjects and calls Draw on each Game Object

	const char* m_ApplicationName = "Asteroids";
	Image m_ApplicationLogo;

	const int m_TargetFPS	 = 120;
	const int m_WindowWidth  = 1000;
	const int m_WindowHeight = 1000;
	int m_WindowScaleX; // = WindowWidth / WindowHeight
	int m_WindowScaleY; // = WindowHeight / WindowWidth

	std::vector<GameObject*> m_GameObjects; // Vector List of all GameObjects*
};

template < typename T, typename... Args >
T* EngineAPI::InstantiateObject( Args ...a_Args )
{
	return new T( a_Args... );
}