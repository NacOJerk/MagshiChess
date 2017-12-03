#include "King.h"

King::King(Board* board, COLOR side) : Piece::Piece(board, side, KING), _moved(false)
{
	_codeName = side == WHITE ? 'K' : 'k';
}

bool King::canMove(string s)
{
	if (!checkPoint("" + s[0] + s[1]) || !checkPoint("" + s[2] + s[3]))
	{
		return false;
	}
	if (s[0] - s[2] > 1 || s[0] - s[2] < -1 || s[1] - s[3] > 1 || s[1] - s[3] < -1)
	{
		return false;
	}
	
	Board b = getBoard();
	Piece* p = &b.getPiece("" + s[2] + s[3]);
	if (p->getSymbol() != '#' && p->getColor == getColor())
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
	}
	b.movePiece("" + s[2] + s[3] + s[0] + s[1]);
	
	return true;
}

void King::move(string s)
{
	if (canMove(s))
	{
		Board b = getBoard();
		b.movePiece(s);
		_moved = true;
	}
}

bool King::hasMoved()
{
	return _moved;
}

bool King::checkPoint(string s)
{
	if (s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8')
	{
		return false;
	}
	return true;
}