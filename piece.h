#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include <cassert>
#include "vec2.h"

enum PieceType { S, Z, L, J, SQR, I, T };

class Piece
{
public:
	bool can_move = true;
	bool right = true, left = true;
	bool move_right = true;
	bool move_left = true;
	Vec2 a, b, c, d;
	Piece();
	void CheckBoundaryCollision();
	void CheckCollision(std::vector<Piece>);
	void Rotate();
	void operator + (char);
	void operator - (char);
	bool operator == (Piece);
};