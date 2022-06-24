#pragma once
#include <raylib.h>
#include "vec2.h"

enum PieceType { S, Z, L, J, SQR, I, T };

class Piece
{
public:
	Vec2 a, b, c, d;
	Piece();
	void Rotate();
};
