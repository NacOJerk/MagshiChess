#include "Queen.h"

Queen::Queen(Board * board, COLOR side) : Piece(board, side, QUEEN), _bishop(board, side), _rook(board, side)
{
	_codeName = side == WHITE ? 'Q' : 'q';
}

bool Queen::canMove(string s)
{
	return _bishop.canMove(s) || _rook.canMove(s);
}
