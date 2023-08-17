#include "GameManager.h"
#include "Asteroid.h"
#include <iostream>
#include <string>

void GameManager::Update(float a_DeltaTime)
{
	GameManager::SpawnAsteroids(a_DeltaTime);
}

#pragma region Player Score Handling

void GameManager::DisplayScore(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize)
{
	DrawText( std::to_string( m_Score ).c_str(), a_PosX, a_PosY, a_FontSize, a_Colour );
}

#pragma endregion 

#pragma region Asteroid Spawn Handling

void GameManager::SpawnAsteroids(float a_DeltaTime)
{
	m_TimeSinceLastSpawn += a_DeltaTime;
	float TimeUntilNextSpawn = 5.0f / m_GameDifficulty;

	if (m_TimeSinceLastSpawn > TimeUntilNextSpawn)
	{
		SpawnRandomAsteroid();
		m_TimeSinceLastSpawn = 0.0f;
	}
}

void GameManager::SpawnRandomAsteroid()
{
	int Size = 1; //GetRandomValue(1, 3);

	// SpawnPos Calculation
	Vec3 SpawnPos{};
	int Side = GetRandomValue(1, 4);
	switch (Side)
	{
	case 1: // Left Side
		SpawnPos.x = 0;
		SpawnPos.y = GetRandomValue(0, EngineAPI::GetWindowHeight());
		break;
	case 2: // Top Side
		SpawnPos.x = GetRandomValue(0, EngineAPI::GetWindowWidth());
		SpawnPos.y = 0;
		break;
	case 3: // Right Side
		SpawnPos.x = EngineAPI::GetWindowWidth();
		SpawnPos.y = GetRandomValue(0, EngineAPI::GetWindowHeight());
		break;
	case 4: // Bottom Side
		SpawnPos.x = GetRandomValue(0, EngineAPI::GetWindowWidth());
		SpawnPos.y = EngineAPI::GetWindowHeight();
		break;
	}

	

	float Rotation = GetRandomValue(0, 360);
	float Speed = GetRandomValue(100, 400);

	EngineAPI::InstantiateObject<Asteroid>(Size, SpawnPos, Rotation, Speed);
}

#pragma endregion