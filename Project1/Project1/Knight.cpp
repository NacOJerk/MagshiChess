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
	Board* b = getBoard();
	Piece* p = b->getPiece(s.substr(2, 2));
	if (p != nullptr && p->getColor() == getColor())
	{
		return false;
	}

	return true;
}