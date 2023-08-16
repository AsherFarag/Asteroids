#include "GameManager.h"
#include <iostream>
#include <charconv>
#include <string>

#pragma region Player Score Handling

void GameManager::DisplayScore(int a_PosX, int a_PosY, Color a_Colour, int a_FontSize)
{
	DrawText( std::to_string( m_Score ).c_str(), a_PosX, a_PosY, a_FontSize, a_Colour );
}

#pragma endregion 


