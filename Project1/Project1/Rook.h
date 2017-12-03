#pragma once
#include "Piece.h"

class Rook : public Piece
{
private:
	bool _moved;
public:
	Rook(Board* board, COLOR side);
	bool canMove(string s);
	void move(string s);
	bool hasMoved();
};