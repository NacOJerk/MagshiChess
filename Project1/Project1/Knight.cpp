#include "Knight.h"
#include <math.h>

Knight::Knight(Board* board, COLOR side) : Piece::Piece(board, side, KNIGHT)
{
	_codeName = side == WHITE ? 'N' : 'n';
}

bool Knight::canMove(string s)
{
	if ((abs(s[0] - s[2]) != 2 || abs(s[1] - s[3]) != 1) && (abs(s[0] - s[2]) != 1 || abs(s[1] - s[3]) != 2))
	{
		return false;
	}
	Board b = getBoard();
	Piece* p = &b.getPiece("" + s[2] + s[3]);
	if (p != nullptr && p->getColor == getColor())
	{
		return false;
	}

	return true;
}

void Knight::move(string s)
{
	if (canMove(s))
	{
		Board b = getBoard();
		b.movePiece(s);
		_threat = isThreating();
	}
}

bool Knight::checkPoint(string s)
{
	if (s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8')
	{
		return false;
	}
	return true;
}