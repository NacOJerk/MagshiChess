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
	COLOR getTurn() const;
	Board& getBoard() const;
	char* serializeBoard() const;
	char* movePlayer(string action);
private:
	COLOR _turn;
	Board* _board;
};

int getNum(char s);