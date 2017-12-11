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
	virtual bool canMove(string) = 0;//This virtual function checks if the tool can move to the desired location
	virtual void move(string);//This function is made to notify the tool that it has moved
	char getSymbol() const;// Returns the piece's symbol
	Board* getBoard();//Gets the board that the piece is on
	COLOR getColor() const;//The color of the piece
	TYPE getType() const;//The type of the piece
protected:
	bool canCastle(string cor); //checks if the player can make a castling move

	char _codeName;
private:
	COLOR _color;
	Board* _board;
	TYPE _type;
};