#pragma once
#include "Piece.h"
#include <math.h>

class Pawn : public Piece
{
private:
	bool _moved;
public:
	Pawn(Board* board, COLOR side);
	bool canMove(string s);
	void move(string s);
	bool hasMoved();
};