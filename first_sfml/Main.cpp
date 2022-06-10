#include <iostream>

#include "Game.h"

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	Game game;

	//The game is on;
	while (game.getWindow()->isOpen()) {

		//using threads
		

		//update
		game.update();
		//render 
		game.render();
	}

	//End of the game;;
	return 0;
}