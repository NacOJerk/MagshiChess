#include "King.h"

King::King(Board* board, COLOR side) : Piece::Piece(board, side, KING), _moved(false)
{
	_codeName = side == WHITE ? 'K' : 'k';
}

bool King::canMove(string s)
{
	if (s[0] - s[2] > 1 || s[0] - s[2] < -1 || s[1] - s[3] > 1 || s[1] - s[3] < -1)
	{
		return false;
	}
	
	Board* b = getBoard();
	Piece* p = b->getPiece(string() + s[2] + s[3]);
	if (p != nullptr && p->getColor() == getColor())
	{
		return false;
	}
	
	return true;
}

void King::move(string s)
{
		_moved = true;
}

bool King::hasMoved()
{
	return _moved;
}