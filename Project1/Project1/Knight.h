#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Board* board, COLOR side);
	bool canMove(string s);
};