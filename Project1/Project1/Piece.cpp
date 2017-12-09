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

bool Piece::canCastle(string cor)
{
	string corrects[8] = { "a1e1", "e1a1", "h1e1", "e1h1", "a8e8", "e8a8", "h8e8", "e8h8" };
	int i = 0, checkPlaces = 4;
	char checkStart = 'e';
	string king, rook;
	for (i = 0; i < 8; i++)
	{
		if (cor == corrects[i])
		{
			break;
		}
	}
	if (i == 8)
	{
		return false;
	}
	 
	king = "" + ((i % 2 == 0) ? cor[2] + cor[3] : cor[0] + cor[1]);
	rook = "" + ((i % 2 == 0) ? cor[0] + cor[1] : cor[2] + cor[3]);
	if (_board->getPiece(king) == nullptr || _board->getPiece(rook) == nullptr)
	{
		return false;
	}
	if (_board->getPiece(king)->getType() != KING || _board->getPiece(rook)->getType() != ROOK)
	{
		return false;
	}
	King* k = (King*)_board->getPiece(king);
	Rook* r = (Rook*)_board->getPiece(rook);
	if (k->hasMoved() || r->hasMoved())
	{
		return false;
	}
	if (rook[0] < king[0])
	{
		checkStart = 'a';
		checkPlaces = 5;
	}
	for (int j = 0; j < checkPlaces; j++)
	{
		string loc = "" + (char)(j + checkStart) + rook[1];
		if (_board->getPiece(loc) != nullptr && loc[0] != king[0] && loc[0] != rook[0])
		{
			return false;
		}
		if (_board->isThreating(loc, getColor()))
		{
			return false;
		}
	}
	return true;
}