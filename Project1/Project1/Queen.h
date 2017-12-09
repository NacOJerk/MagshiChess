#pragma once
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"

class Queen :
	public Piece
{
public:
	Queen(Board* board, COLOR side);
	bool canMove(string s);
private:
	Bishop _bishop;
	Rook _rook;
};

