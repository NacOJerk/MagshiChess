#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(Board* board, COLOR side);
	bool canMove(string s);
};

