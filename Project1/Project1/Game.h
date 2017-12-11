#pragma once
#include <string>
#include "Board.h"

class Board;
using std::string;


enum COLOR { WHITE, BLACK };
enum TYPE { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

typedef enum COLOR COLOR;
typedef enum TYPE TYPE;

class Game
{
public:
	Game();
	~Game();
	COLOR getTurn() const;//Returns who is playing right now
	Board* getBoard() const;//Returns the board object 
	char* serializeBoard() const;//This function serializes the board to a string
	char* movePlayer(string action);//This function deals with the frontend input
private:
	COLOR _turn;
	Board* _board;
};

int getNum(char s);