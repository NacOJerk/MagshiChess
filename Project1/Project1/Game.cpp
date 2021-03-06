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

Board* Game::getBoard() const
{
	return _board;
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
	for (char a = '8'; a >= '1'; a--)
	{
		for (char j = 'a';j <= 'h'; j++)
		{
			string loc = string() + j + a;
			str += (getBoard()->getPiece((loc)) == nullptr) ? '#' : getBoard()->getPiece(loc)->getSymbol();
		}
	}
	str += _turn == WHITE ? '0' : '1';
	char* chars = new char[str.size() + 1];
	for (int i = 0; i < str.size(); i++)
	{
		chars[i] = str[i];
	}
	chars[str.size()] = '\0';
	return chars;
}

bool checkPoint(string s)
{
	return ('a' <= s[0] && s[0] <= 'h' && '1' <= s[1] && s[1] <= '8');
}

char* Game::movePlayer(string action)
{
	char* chars = new char[2];
	chars[1] = '\0';
	string origin = action.substr(0, 2);
	string dest = action.substr(2, 2);
	COLOR oppisiteSide = getTurn() == WHITE ? BLACK : WHITE;
	//0 a
	//1 a
	//2 a
	//3 a
	//4 a
	//5 a
	//6 a
	//7 a
	//8
	if (origin != dest)
	{
		if (checkPoint(origin) && checkPoint(dest))//Check that the origin and dest are legal
		{
			if (getBoard()->getPiece(origin) != nullptr && getBoard()->getPiece(origin)->getColor() == getTurn())
			{
				bool hasHisPlayerThere = getBoard()->getPiece(dest) != nullptr && getBoard()->getPiece(dest)->getColor() == getTurn();
				if (!hasHisPlayerThere)
				{
					if (getBoard()->canMove(action))
					{
						Piece* savyPicy = getBoard()->movePiece(action);
						if (getBoard()->isThreating(getBoard()->getKingLoc(getTurn()), getTurn()))
						{ 
							chars[0] = '4';
							getBoard()->movePiece(dest + origin);
							getBoard()->getPiece(dest) = savyPicy;
						}
						else
						{
							savyPicy ? delete savyPicy : 1;
							getBoard()->getPiece(dest)->move(dest);
							
							if (getBoard()->isThreating(getBoard()->getKingLoc(oppisiteSide), oppisiteSide))//Chess
							{
								//ADD TEST HERE FOR CHECKMATES
								chars[0] = '1';
							}
							else
							{
								chars[0] = '0';
							}
							_turn = _turn == WHITE ? BLACK : WHITE;
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