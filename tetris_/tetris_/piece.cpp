#include "piece.h"
#include <cstdlib>
#include <ctime>

Piece::Piece()
{
	std::srand(std::time(NULL));
	int type = std::rand() % 7;
	switch (type)
	{
	case S: a = Vec2(1, 5); b = Vec2(1, 4); c = Vec2(0, 4); d = Vec2(2, 5);
		break;
	case Z: a = Vec2(1, 4); b = Vec2(1, 5); c = Vec2(0, 5); d = Vec2(2, 4);
		break;
	case L: a = Vec2(1, 5); b = Vec2(1, 4); c = Vec2(1, 6); d = Vec2(0, 6);
		break;
	case J: a = Vec2(1, 5); b = Vec2(1, 4); c = Vec2(1, 6); d = Vec2(0, 4);
		break;
	case SQR: a = Vec2(1, 5); b = Vec2(1, 4); c = Vec2(0, 5); d = Vec2(0, 4);
		break;
	case I: a = Vec2(1, 5); b = Vec2(1, 4); c = Vec2(1, 6); d = Vec2(1, 7);
		break;
	case T: a = Vec2(1, 5); b = Vec2(1, 4); c = Vec2(1, 6); d = Vec2(0, 5);
		break;
	default:
		break;
	}
}
