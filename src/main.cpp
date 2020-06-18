#include <iostream>
#include "EventHandler.hpp"


#define SDL_main main

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	zmgfx::Screen *screen = new Screen(); 
	
	Board *board = new Board(3, 3, screen);

	EventHandler *eventHandler = new EventHandler(board);


	
	screen->init("Tic Tac Toe");
	
	board->init();
	screen->update();
	board->drawBoard();
	screen->update();
	while(eventHandler->processEvents())
	{
		// keep looping until close

	}
	screen->close();
	
	delete eventHandler;
	delete board;
	delete screen;

	return 0;
}