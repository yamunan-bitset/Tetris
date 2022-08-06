#pragma once
#include "piece.h"

struct Vec2
{
	int x, y;
	Vec2() {}
	Vec2(int _x, int _y) : x(_x), y(_y) {}
	bool operator == (Vec2 vec22)
	{
		if (x == vec22.x && y == vec22.y)
			return true;
		return false;
	}
};