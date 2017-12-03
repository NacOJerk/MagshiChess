#include "Pawn.h"

Pawn::Pawn(Board* board, COLOR side) : Piece(board, side, PAWN), _moved(false)
{
	_codeName = side == WHITE ? 'P' : 'p';
}

bool Pawn::canMove(string s)
{
	if (!checkPoint("" + s[0] + s[1]) || !checkPoint("" + s[2] + s[3]))
	{
		return false;
	}
	if (abs(s[0] - s[2]) > 1 || s[3] - s[1] > _moved ? 1 : 2)
	{
		return false;
	}

	Board b = getBoard();
	Piece* p = &b.getPiece("" + s[2] + s[3]);
	if ((p->getSymbol() == '#' || p->getColor() == getColor()) && s[0] != s[2] || p->getSymbol() != '#')
	{
		return false;
	}
	if (!canMove("" + s[0] + s[1] + s[2] + (char)(s[3] + 1)))
	{
		return false;
	}
	if (p->getType() != KING)
	{
		b.movePiece(s);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				p = &b.getPiece("" + (char)('a' + i) + (char)('1' + j));
				if (p->getSymbol() != '#' && p->getColor() != getColor() && p->isThreating())
				{
					b.movePiece("" + s[2] + s[3] + s[0] + s[1]);
					return false;
				}
			}
		}
		b.movePiece("" + s[2] + s[3] + s[0] + s[1]);
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