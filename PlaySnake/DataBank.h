#pragma once
#include <string>
#include <vector>

struct Vector2 {
	Vector2() = default;

	Vector2(int x, int y)
	{
		X = x;
		Y = y;
	}

	int X, Y;
};

class DataBank 
{
public: static int areaS;
		static bool PlayGame;
		static bool die;
		static bool teleport;
		static int score;
		static int total_score;
		static bool loadGame;
		static int cordX_snake;
		static int cordY_snake;
		static int cordX_fruit;
		static int cordY_fruit;
		static std::vector< Vector2 > rocks;
		static std::vector< Vector2 > snakes;
		static int directionX;
		static int directionY;

};

