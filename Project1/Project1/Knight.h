#pragma once
#include "Piece.h"

class Knight : public Piece
{
private:
	bool checkPoint(string s);
public:
	Knight(Board* board, COLOR side);
	bool canMove(string s);
	void move(string);
};