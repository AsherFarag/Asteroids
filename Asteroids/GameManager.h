#pragma once

#include "raylib.h"

class GameManager
{
public:
	GameManager()  {}
	~GameManager() {}

private:

	#pragma region Player Score Handling

public:
	int  GetScore() { return m_Score; }
	void AddScore(int a_Points) { m_Score += a_Points; }
	void DisplayScore(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize);

private:
	int m_Score = 0;

	#pragma endregion

};

