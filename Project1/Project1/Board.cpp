#include "Board.h"

Board::Board(Game* game) : _game(game)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(*this)(i, j) = nullptr;
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(*this)(i, j) == nullptr ? 1 : delete (*this)(i, j);
		}
	}
}

bool Board::canMove(string mov)
{
	return (*this)(getNum(mov[0]), getNum(mov[1]))->canMove(mov);
}


void Board::deletePiece(string loc)
{
	delete (*this)(getNum(loc[0]), getNum(loc[1]));
	(*this)(getNum(loc[0]), getNum(loc[1])) = nullptr;
}

Piece* Board::movePiece(string mov)
{
	Piece* piece = getPiece(mov.substr(2, 2));
	getPiece(mov.substr(2, 2)) = getPiece(mov.substr(0, 2));
	getPiece(mov.substr(0, 2)) = nullptr;
	return piece;
}

Piece*& Board::operator()(int x, int y)
{
	return _piece[x][y];
}

const Game& Board::getGame()
{
	return *_game;
}

Piece*& Board::getPiece(string loc)
{
	return _piece[getNum(loc[0])][getNum(loc[1])];
}