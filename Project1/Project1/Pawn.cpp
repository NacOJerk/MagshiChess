#include "Pawn.h"

Pawn::Pawn(Board* board, COLOR side) : Piece(board, side, PAWN), _moved(false)
{
	_codeName = side == WHITE ? 'P' : 'p';

}

bool Pawn::canMove(string s)
{
	if (abs(s[0] - s[2]) > 1 || s[3] - s[1] > _moved ? 1 : 2)
	{
		return false;
	}

	Board b = getBoard();
	Piece* p = &b.getPiece("" + s[2] + s[3]);
	if (s[3] - s[1] == 2)
	{
		p = &b.getPiece("" + s[2] + (char)(s[3] - 1));
		if (p != nullptr)
		{
			return false;
		}
	}
	p = &b.getPiece("" + s[2] + s[3]);
	if (((p == nullptr || p->getColor() == getColor()) && s[0] != s[2]) || (p != nullptr && s[0] == s[2]))
	{
		return false;
	}

	return true;
}

void Pawn::move(string s)
{
	if (canMove(s))
	{
		Board b = getBoard();
		b.movePiece(s);
		_moved = true;
		_threat = isThreating();
	}
}

bool Pawn::hasMoved()
{
	return _moved;
}

bool Pawn::checkPoint(string s)
{
	if (s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8')
	{
		return false;
	}
	return true;
}