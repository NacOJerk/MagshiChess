#pragma once
#include "Game.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

class Piece;
class Game;
class Pawn;
class Rook;
class Knight;
class Bishop;
class Rook;
class Queen;
class King;

class Board
{
public:
	Board(Game* game);
	~Board();
	bool canMove(string mov);
	void deletePiece(string loc);
	Piece* movePiece(string mov);
	Piece*& operator()(int x, int y);
	Piece*& getPiece(string loc);
	const Game& getGame();
	bool isThreating(string loc, COLOR side);//Check if the other team is threating the location (the color you give is the one of the "king" or the tool you want to check if it is threatened)
	string getKingLoc(COLOR c) const;
private:
	Game* _game;
	Piece* _piece[8][8];
	string _whiteKingLoc;
	string _blackKingLoc;
};
