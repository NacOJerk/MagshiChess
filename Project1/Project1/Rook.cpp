#include "Rook.h"

Rook::Rook(Board* board, COLOR side) : Piece(board, side, ROOK), _moved(false)
{
	_codeName = getColor() == WHITE ? 'R' : 'r';
}

bool Rook::canMove(string move)
{
	Board board = getBoard();
	string source = move.substr(0, 2);
	string dest = move.substr(2, 2);
	bool canMove = true;
	if (source[0] == dest[0])//Same TOOR
	{
		if (source[1] < dest[1])//Is moving up
		{
			for (int i = 1; i < (dest[1] - source[1]) && canMove; i++)//Loop to check each location
			{
				string location = string(&dest[0]) + (char)(i + source[1]);//Location as string
				if (board.getPiece(location) == nullptr)//If location is empty move on
					continue;
				if (board.getPiece(location)->getColor() == getColor())//If location is equal to my color you cant move any way
				{
					canMove = false;
					continue;
				}
				if (location != dest)//If the other color is equal to me it works
					canMove = false;
			}
		}
		else if(source[1] > dest[1])//Moving down
		{
			for (int i = 1; i < (source[1] - dest[1]) && canMove; i++)//Loop to check each location
			{
				string location = string(&dest[0]) + (char)(source[1] - i);//Location as string
				if (board.getPiece(location) == nullptr)//If location is empty move on
					continue;
				if (board.getPiece(location)->getColor() == getColor())//If location is equal to my color you cant move any way
				{
					canMove = false;
					continue;
				}
				if (location != dest)//If the other color is equal to me it works
					canMove = false;
			}
		}
	}
	else if (source[1] == dest[1])//same row
	{
		if (source[0] < dest[0])//Moving right
		{
			for (int i = 1; i < (dest[0] - source[0]) && canMove; i++)
			{
				string location = string(&source[0] + i) + (char)(source[1]);//Location as string
				if (board.getPiece(location) == nullptr)
					continue;
				if (board.getPiece(location)->getColor() == getColor())//If location is equal to my color you cant move any way
				{
					canMove = false;
					continue;
				}
				if (location != dest)//If the other color is equal to me it works
					canMove = false;
			}
		}
		else if (source[0] > dest[0])//Moving left
		{
			for (int i = 1; i < (source[0] - dest[0]) && canMove; i++)
			{
				string location = string(&source[0] - i) + (char)(source[1]);//Location as string
				if (board.getPiece(location) == nullptr)
					continue;
				if (board.getPiece(location)->getColor() == getColor())//If location is equal to my color you cant move any way
				{
					canMove = false;
					continue;
				}
				if (location != dest)//If the other color is equal to me it works
					canMove = false;
			}
		}
	}
	else
	{
		canMove = false;
	}
	return canMove;
}

bool Rook::hasMoved()
{
	return this->_moved;
}

void Rook::move(string s)
{
	_moved = true;
}
