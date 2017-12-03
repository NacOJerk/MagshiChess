#include "Game.h"

Game::Game() : _turn(WHITE)
{
	_board = new Board(this);
}

Game::~Game()
{
	delete _board;
}

COLOR Game::getTurn()
{
	return _turn;
}

const Board& Game::getBoard()
{
	return *_board;
}

char* Game::serializeBoard()
{
	Piece* pieces[][8] = (*_board).getPieces();
	string str("");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			str += pieces[i][j]->getSymbol();
		}
	}
	str += _turn == WHITE ? '0' : '1';
	char* chars = new char[str.size() + 1];
	for (int i = 0; i < str.size(); i++)
	{
		chars[i] = str[i];
	}
	chars[str.size() + 1] = '\0';
	return chars;
}

char* Game::movePlayer(string action)
{
	char* chars = new char[2];
	chars[1] = '\0';
	string origin = action.substr(0, 2);
	string dest = action.substr(2, 2);
	if (origin != dest)
	{
		if (true)//Check that the origin and dest are legal
		{
			if (getBoard().getPiece(origin) != nullptr && getBoard().getPiece(origin)->getColor() == getTurn())
			{
				bool hasHisPlayerThere = getBoard().getPiece(dest) != nullptr && getBoard().getPiece(dest)->getColor() == getTurn();
				if (!hasHisPlayerThere)
				{
					if (getBoard().canMove(action))
					{
						//Check somehow if it will make it have a chess
						//also move stuff
					}
					else
					{
						chars[0] = '6';
					}
				}
				else
				{
					chars[0] = '3';
				}
			}
			else
			{
				chars[0] = '2';
			}
		}
		else
		{
			chars[0] = '5';
		}
	}
	else
	{
		chars[0] = '7';
	}
	return chars;
}