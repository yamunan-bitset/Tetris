#pragma once
#include <raylib.h>
#include <string>
#include "vec2.h"

enum PieceType { S, Z, L, J, SQR, I, T };

class Piece
{
public:
	bool can_move = true;
	bool right = true, left = true;
	Vec2 a, b, c, d;
	Piece();
	void CheckBoundaryCollision();
	void Rotate();
	void operator + (char);
	void operator - (char);
};