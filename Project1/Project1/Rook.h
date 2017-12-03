#pragma once
#include "Piece.h"
//#include "Board.h"
#include <iostream>
#include <string>
using namespace std;
class Rook : public Piece
{
public:
	Rook(bool side);
	~Rook() = default;
	bool canMove(string location);
	bool hasMoved();
private:
	bool _moved;

};