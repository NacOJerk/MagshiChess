#include "Pawn.h"

Pawn::Pawn(Board* board, COLOR side) : Piece(board, side, PAWN), _moved(false)
{
	_codeName = side == WHITE ? 'P' : 'p';

}

bool Pawn::canMove(string move)
{
	Board* board = getBoard();
	string source = move.substr(0, 2);
	string dest = move.substr(2, 2);
	return !getColor();
}

void Pawn::move(string s)
{
		_moved = true;
}

bool Pawn::hasMoved()
{
	return _moved;
}