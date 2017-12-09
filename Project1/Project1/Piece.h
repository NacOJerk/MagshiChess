#pragma once
#include "Board.h"

class Board;

class Piece
{
public:
	Piece(Board* board, COLOR side, TYPE type);
	virtual bool canMove(string) = 0;
	virtual void move(string);
	char getSymbol() const;
	Board& getBoard();
	COLOR getColor() const;
	TYPE getType() const;
protected:
	bool canCastle(string cor); //checks if the player can make a castling move

	char _codeName;
private:
	COLOR _color;
	Board* _board;
	TYPE _type;
};