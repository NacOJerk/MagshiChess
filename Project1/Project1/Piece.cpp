#include "Piece.h"

Piece::Piece(Board* board, COLOR side, TYPE type) : _board(board), _color(side), _type(type)
{

}

void Piece::move(string)
{

}

char Piece::getSymbol() const
{
	return _codeName;
}

Board& Piece::getBoard()
{
	return *_board;
}

COLOR Piece::getColor() const
{
	return _color;
}

TYPE Piece::getType() const
{
	return _type;
}