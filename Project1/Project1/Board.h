#pragma once
#include <string>
#include "Game.h"
#include "Piece.h"

using std::string;

class Piece;
class Game;

typedef enum COLOR COLOR;
typedef enum TYPE TYPE;


class Board
{
public:
	Board(Game* game);//Gets the game and create the board
	~Board();//Frees the board
	bool canMove(string mov);//Checks if a move is legal
	void deletePiece(string loc);// delete's a piece from the board (Kinda unused)
	Piece* movePiece(string mov);// Move's the piece and returns the piece that used to be at the destanation	
	Piece*& operator()(int x, int y);//an operator that gets the pieces from the arrays
	Piece*& getPiece(string loc);//Get's piece from a given location	
	const Game& getGame();//Return's the original game
	bool isThreating(string loc, COLOR side);//Check if the other team is threating the location (the color you give is the one of the "king" or the tool you want to check if it is threatened)
	string getKingLoc(COLOR c) const;//Return's the location of the king
private:
	Game* _game;
	Piece* _piece[8][8];
	string _whiteKingLoc;
	string _blackKingLoc;
};
