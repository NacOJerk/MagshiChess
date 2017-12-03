#pragma once
#include "Board.h"

class Board;

class Piece
{
public:
	Piece(Board* board, COLOR side, TYPE type);
	virtual bool canMove(string) = 0;
	virtual void move(string);
	char getSymbol();
	const Board& getBoard();
	COLOR getColor();
	TYPE getType();
	bool isThreating();
protected:
	char _codeName;
	bool _threat;
private:
	COLOR _color;
	Board* _board;
	TYPE _type;
};