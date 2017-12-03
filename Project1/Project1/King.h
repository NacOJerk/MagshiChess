#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	bool _moved;
	bool checkPoint(string s);
public:
	King(Board* board, COLOR side);
	bool canMove(string s);
	void move(string s);
	bool hasMoved();
};