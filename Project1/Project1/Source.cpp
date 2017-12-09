#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Game.h"

using namespace std;

void main()
{
	srand(time_t(NULL));
	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	
	Game* game = new Game();

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	char* boardLoc = game->serializeBoard();

	strcpy_s(msgToGraphics, boardLoc); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	delete boardLoc;

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	char* response = nullptr;
	while (msgFromGraphics != "quit")
	{
		
		response = game->movePlayer(msgFromGraphics);
		
		// YOUR CODE
		strcpy_s(msgToGraphics, response); // msgToGraphics should contain the result of the operation




		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
	delete game;
}