#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include <iostream>

Board::Board(Game* game) : _game(game)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(*this)(i, j) = nullptr;
		}
	}
	//Rooks
	getPiece("a8") = new Rook(this, BLACK);
	getPiece("h8") = new Rook(this, BLACK);
	getPiece("a1") = new Rook(this, WHITE);
	getPiece("h1") = new Rook(this, WHITE);
	//Knights
	getPiece("b8") = new Knight(this, BLACK);
	getPiece("g8") = new Knight(this, BLACK);
	getPiece("b1") = new Knight(this, WHITE);
	getPiece("g1") = new Knight(this, WHITE);
	//Bishops
	getPiece("c8") = new Bishop(this, BLACK);
	getPiece("f8") = new Bishop(this, BLACK);
	getPiece("c1") = new Bishop(this, WHITE);
	getPiece("f1") = new Bishop(this, WHITE);
	//The Black Royal Family
	getPiece("d8") = new King(this, BLACK);
	_blackKingLoc = "d8";
	getPiece("e8") = new Queen(this, BLACK);
	//The White Royal Family
	getPiece("d1") = new King(this, WHITE);
	_whiteKingLoc = "d1";
	getPiece("e1") = new Queen(this, WHITE);
	//Creating the pawns
	for (char c = 'a'; c <= 'h'; c++)
	{
		getPiece((string() + c + '7')) = new Pawn(this, BLACK);
		getPiece((string() + c + '2')) = new Pawn(this, WHITE);
	}
}

Board::~Board()
{
	std::cout << "hey";
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
	if (getPiece(mov))
		return getPiece(mov)->canMove(mov);
	else
		return false;
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
	if (getPiece(mov.substr(2, 2))->getType() == KING)
	{
		if (getPiece(mov.substr(2, 2))->getColor() == WHITE)
		{
			_whiteKingLoc = mov.substr(2, 2);
		}
		else if(getPiece(mov.substr(2, 2))->getColor() == BLACK)
		{
			_blackKingLoc = mov.substr(2, 2);
		}
	}
	return piece;
}

string getLoc(int row, int colum)
{
	char letter = colum + 'a';
	return string() + letter + (char)(row + '1');
}

bool Board::isThreating(string loc, COLOR side)
{
	bool threat = false;
	for (int i = 0; i < 8 * 8 && !threat; i++, threat = (getPiece(getLoc(i / 8, i % 8)) != nullptr && getPiece(getLoc(i / 8, i % 8))->getColor() == side) ? threat : canMove(getLoc(i / 8, i % 8) + loc));
	/*{
		for (int j = 0; j < 8 && threat; j++)
		{
			if (getPiece(getLoc(i, j))->getColor() == side)
			{
				continue;
			}
			threat = canMove(getLoc(i, j) + loc);
		}
	}*/
	return threat;
}

Piece*& Board::operator()(int x, int y)
{
	return _piece[7-y][x];
}

const Game& Board::getGame()
{
	return *_game;
}

Piece*& Board::getPiece(string loc)
{
	return (*this)(getNum(loc[0]),getNum(loc[1]));
}

string Board::getKingLoc(COLOR c) const
{
	return c == WHITE ? _whiteKingLoc : _blackKingLoc;
}