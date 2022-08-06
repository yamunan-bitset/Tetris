#include "piece.h"
#include <cstdlib>
#include <ctime>

Piece::Piece()
{
	std::srand(std::time(NULL));
	int type = std::rand() % 7;
	int start_x = std::rand() % 11;
	switch (type)
	{
	case S: a = Vec2(start_x + 1, 1); b = Vec2(start_x + 1, 0); c = Vec2(start_x, 0); d = Vec2(start_x + 2, 1);
		break;
	case Z: a = Vec2(start_x + 1, 0); b = Vec2(start_x + 1, 1); c = Vec2(start_x, 1); d = Vec2(start_x + 2, 0);
		break;
	case L: a = Vec2(start_x + 1, 1); b = Vec2(start_x + 1, 0); c = Vec2(start_x + 1, 2); d = Vec2(start_x, 2);
		break;
	case J: a = Vec2(start_x + 1, 1); b = Vec2(start_x + 1, 0); c = Vec2(start_x + 1, 2); d = Vec2(start_x, 0);
		break;
	case SQR: a = Vec2(start_x + 1, 1); b = Vec2(start_x + 1, 0); c = Vec2(start_x, 1); d = Vec2(start_x, 0);
		break;
	case I: a = Vec2(start_x + 1, 1); b = Vec2(start_x + 1, 0); c = Vec2(start_x + 1, 2); d = Vec2(start_x + 1, 3);
		break;
	case T: a = Vec2(start_x + 1, 1); b = Vec2(start_x + 1, 0); c = Vec2(start_x + 1, 2); d = Vec2(start_x, 1);
		break;
	default:
		break;
	}
}

void Piece::CheckBoundaryCollision()
{
	if (a.x == 0)
		left = false;
	else if (a.x == 11)
		right = false;
	else if (b.x == 0)
		left = false;
	else if (b.x == 11)
		right = false;
	else if (c.x == 0)
		left = false;
	else if (c.x == 11)
		right = false;
	else if (d.x == 0)
		left = false;
	else if (d.x == 11)
		right = false;
	else
	{
		right = true;
		left = true;
	}
}

#include <iostream>

void Piece::CheckCollision(std::vector<Piece> pieces)
{
	if (a == pieces.back().a && b == pieces.back().b && c == pieces.back().c && d == pieces.back().d)
		std::cout << "No error!" << std::endl;
	else std::cout << "Error!" << std::endl;
	/*
	for (Piece piece : pieces)
		if (piece.a.x == a.x || piece.b.x == b.x || piece.c.x == c.x || piece.d.x == d.x
			|| )
			*/
}

void Piece::operator + (char type)
{
	CheckBoundaryCollision();
	if (type == 'x')
	{
		if (right) 
		{ 
			a.x++; b.x++; c.x++; d.x++;
		}
	}
	if (type == 'y')
	{
		a.y++; b.y++; c.y++; d.y++;
	}
}

void Piece::operator - (char type)
{
	CheckBoundaryCollision();
	if (type == 'x')
	{
		if (left)
		{
			a.x--; b.x--; c.x--; d.x--;
		}
	}
	if (type == 'y')
	{
		a.y--; b.y--; c.y--; d.y--;
	}
}

bool Piece::operator == (Piece piece1)
{
	if (a == piece1.a && b == piece1.b && c == piece1.c && d == piece1.d)
		return true;
	return false;
}

void Piece::Rotate()
{
}