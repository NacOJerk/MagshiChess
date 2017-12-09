#pragma once
#include "Board.h"
#include <string>

using std::string;

class Board;

typedef enum COLOR COLOR;
typedef enum TYPE TYPE;

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
	char _codeName;
private:
	COLOR _color;
	Board* _board;
	TYPE _type;
};