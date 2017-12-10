#include "Pawn.h"
#include <math.h>

Pawn::Pawn(Board* board, COLOR side) : Piece(board, side, PAWN), _moved(false)
{
	_codeName = side == WHITE ? 'P' : 'p';

}

bool Pawn::canMove(string move)
{
	Board* board = getBoard();
	string source = move.substr(0, 2);
	string dest = move.substr(2, 2);
	int differentX = dest[0] - source[0];
	int differentY = dest[1] - source[1];

	if (abs(differentX) > 1 )
		return false;
	if (abs(differentY) > 2 || abs(differentY) < 1)
		return false;
	if (differentY < 0 && getColor() == WHITE || differentY > 0 && getColor() == BLACK)
		return false;

	if (abs(differentY) == 2 && hasMoved())
		return false;
	
	if (abs(differentX) > 0 && board->getPiece(dest) == nullptr)
		return false;

	if(differentX == 0)
		for (int i = 1; i <= abs(differentY); i++)
		{
			string loc = string() +
				source.substr(0, 1) +
				(char)(source[1] + (getColor() == WHITE ? i : -i));
			if (board->getPiece(loc) != nullptr)
			{
				return false;
			}
		}

	return true;

}

void Pawn::move(string s)
{
		_moved = true;
}

bool Pawn::hasMoved()
{
	return _moved;
}