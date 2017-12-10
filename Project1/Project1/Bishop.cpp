#include "Bishop.h"



Bishop::Bishop(Board* board, COLOR side) : Piece(board, side, BISHOP)
{
	_codeName = getColor() == WHITE ? 'B' : 'b';
}

bool Bishop::canMove(string move)
{
	Board board = getBoard();
	string source = move.substr(0, 2);
	string dest = move.substr(2, 2);
	int diffrentX = dest[0] - source[0];
	int diffrentY = dest[1] - source[1];
	bool canMove = true;
	if (abs(diffrentX) == abs(diffrentY))//This will make sure the movement is fine
	{
		for (int i = 1; i < abs(diffrentX); i++)
		{
			string location = //Creating the location as a string
				string() + (&source[0] + (diffrentX > 0 ? i : -i)) +
				(char)(source[1] + (diffrentY > 0 ? i : -i));
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
	else
	{
		canMove = false;
	}
	return canMove;
}
