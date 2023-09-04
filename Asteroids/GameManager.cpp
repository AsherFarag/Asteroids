#include "GameManager.h"
#include "Asteroid.h"
#include "SpaceCraft.h"
#include <iostream>
#include <string>

#define SCORE_TO_DIFFICULTY_SCALE 0.0001f;

void GameManager::Update(float a_DeltaTime)
{
	SpawnAsteroids(a_DeltaTime);
}

void GameManager::Restart()
{
	m_GameOver = false;
	m_Score = 0;
	m_PlayerLives = 3;
	RespawnPlayer();
}

#pragma region Player Handling

void GameManager::AddScore(int a_Points)
{
	if (m_GameOver == false)
	{
		m_Score += a_Points;

		// Adds an Increment of Difficulty Scaled by the Score added
		m_GameDifficulty += (float)a_Points * SCORE_TO_DIFFICULTY_SCALE;
		if (m_GameDifficulty > m_MaxGameDifficulty)
			m_GameDifficulty = m_MaxGameDifficulty;
	}
}

void GameManager::DisplayScore(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize)
{
	DrawText( std::to_string( m_Score ).c_str(), a_PosX, a_PosY, a_FontSize, a_Colour );
}

void GameManager::DisplayLives(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize)
{
	string PlayerLives = "Lives: " + std::to_string(m_PlayerLives);
	DrawText(PlayerLives.c_str(), a_PosX, a_PosY, a_FontSize, a_Colour);
}

void GameManager::DisplayDeathScreen()
{
	const char* Text = "GAME OVER!";
	int FontSize = 100;
	float TextWidth = MeasureText(Text, FontSize);

	DrawText(Text,
		(EngineAPI::GetWindowWidth() - TextWidth) / 2, // Draws at the middle of Screen Width
		(EngineAPI::GetWindowHeight() / 2) - FontSize, // Draws at the middle of Screen Height
		FontSize,
		RED);
}

void GameManager::DisplayRestartButton()
{
	RestartButton.x = EngineAPI::GetWindowWidth() / 2 - 150; // Middle of Screen Width
	RestartButton.y = EngineAPI::GetWindowHeight() / 2; // Middle of Screen Height

	if (CheckCollisionPointRec(GetMousePosition(), RestartButton))
	{
		DrawRectangle(
			RestartButton.x,
			RestartButton.y,
			RestartButton.width,
			RestartButton.height,
			GREEN);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Restart();
		}
	}
	else
	{
		DrawRectangle(
			RestartButton.x,
			RestartButton.y,
			RestartButton.width,
			RestartButton.height,
			RED);
	}

	DrawText("Restart",
		EngineAPI::GetWindowWidth() / 2 - 140, // Draws at the middle of Screen Width
		EngineAPI::GetWindowHeight() / 2 + 15, // Draws at the middle of Screen Height
		70,
		WHITE);
}

void GameManager::RespawnPlayer()
{
	EngineAPI::ClearGameObjects(); // Clears all objects from the Scene
	EngineAPI::InstantiateObject<SpaceCraft>(); // Instantiates a New SpaceCraft
	Reset(); // Resets Certain Values
}

void GameManager::Reset()
{
	m_TimeSinceLastSpawn = -1; // Adds some time so the Asteroids don't spawn instantly
	m_GameDifficulty = 1.0f; // Starter Difficulty
}

#pragma endregion 

#pragma region Asteroid Spawn Handling

void GameManager::SpawnAsteroids(float a_DeltaTime)
{
	m_TimeSinceLastSpawn += a_DeltaTime;

	// Calculates the New Max Spawn Time based on Difficulty
	float TimeUntilNextSpawn = 5.0f / m_GameDifficulty; // As Difficulty increases, Max Spawn Time decreases

	if (m_TimeSinceLastSpawn > TimeUntilNextSpawn)
	{
		SpawnRandomAsteroid();
		m_TimeSinceLastSpawn = 0.0f;
	}
}

void GameManager::SpawnRandomAsteroid()
{
	int Size = 1; // Size 1 is Large

	// Spawn Position Calculation
	Vec3 SpawnPos{};
	int Side = GetRandomValue(1, 4); // Randomly decides which Side the Asteroid will Spawn on
	switch (Side)
	{
	case 1: // Left Side
		SpawnPos.x = 0;
		SpawnPos.y = GetRandomValue(0, EngineAPI::GetWindowHeight());
		break;
	case 2: // Bottom Side
		SpawnPos.x = GetRandomValue(0, EngineAPI::GetWindowWidth());
		SpawnPos.y = 0;
		break;
	case 3: // Right Side
		SpawnPos.x = EngineAPI::GetWindowWidth();
		SpawnPos.y = GetRandomValue(0, EngineAPI::GetWindowHeight());
		break;
	case 4: // Top Side
		SpawnPos.x = GetRandomValue(0, EngineAPI::GetWindowWidth());
		SpawnPos.y = EngineAPI::GetWindowHeight();
		break;
	}

	float Rotation = GetRandomValue(0, 360);
	float Speed = GetRandomValue(100, 400);

	EngineAPI::InstantiateObject<Asteroid>(Size, SpawnPos, Rotation, Speed);
}

#pragma endregion