#include "Game.h"

Game::Game() : _turn(WHITE)
{
	_board = new Board(this);
}

Game::~Game()
{
	delete _board;
}

COLOR Game::getTurn() const
{
	return _turn;
}

Board& Game::getBoard() const
{
	return *_board;
}

int getNum(char s)
{
	if ('a' <= s && s <= 'z')
	{
		return s - 'a';
	}
	if ('A' <= s && s <= 'Z')
	{
		return s - 'Z';
	}
	return s - '1';
}

char* Game::serializeBoard() const
{
	string str("");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			str += (getBoard()(i, j) == nullptr) ? '#' : getBoard()(i, j)->getSymbol();
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

bool checkPoint(string s)
{
	return ('a' <= s[0] && s[0] < 'h' && '1' <= s[1] && s[1] <= '8');
}

char* Game::movePlayer(string action)
{
	char* chars = new char[2];
	chars[1] = '\0';
	string origin = action.substr(0, 2);
	string dest = action.substr(2, 2);
	//0
	//1
	//2 a
	//3 a
	//4 a
	//5 a
	//6 a
	//7 a
	if (origin != dest)
	{
		if (checkPoint(origin) && checkPoint(dest))//Check that the origin and dest are legal
		{
			if (getBoard().getPiece(origin) != nullptr && getBoard().getPiece(origin)->getColor() == getTurn())
			{
				bool hasHisPlayerThere = getBoard().getPiece(dest) != nullptr && getBoard().getPiece(dest)->getColor() == getTurn();
				if (!hasHisPlayerThere)
				{
					if (getBoard().canMove(action))
					{
						Piece* savyPicy = getBoard().movePiece(action);
						if (getBoard().isThreating(getBoard().getKingLoc(getTurn()), getTurn()))
						{ 
							chars[0] = '4';
							getBoard().movePiece(dest + origin);
							getBoard().getPiece(dest) = savyPicy;
						}
						else
						{
							savyPicy ? delete savyPicy : 1;
							getBoard().getPiece(dest)->move(dest);

							//Chess on other dude
							
						}
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