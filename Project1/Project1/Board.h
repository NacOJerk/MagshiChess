#pragma once
#include "Game.h"
#include "Piece.h"

class Piece;
class Game;

class Board
{
public:
	Board(Game* game);
	~Board();
	bool canMove(string mov) const;
	void deletePiece(string loc) const;
	void movePiece(string mov) const;
	Piece*** getPieces() const;
	Piece* getPiece(string loc) const;
	const Game& getGame();
private:
	Game* _game;
	Piece*** _piece;
};
