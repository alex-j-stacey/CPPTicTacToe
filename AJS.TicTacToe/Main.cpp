
// Tic Tac Toe
// Use this main.cpp to test your TicTacToe class

#include <iostream>
#include <conio.h>
#include "TicTacToe.h"

using namespace std;

int main()
{
	TicTacToe* pGame = nullptr;

	while (true)
	{
		if (pGame) delete pGame;
		pGame = new TicTacToe;

		// play the game
		while (!pGame->IsOver())
		{
			pGame->DisplayBoard();

			int position;
			do
			{
				cout << "Player " << pGame->GetPlayerTurn() << ", select a position (1-9): ";
				cin >> position;
			} while (!pGame->IsValidMove(position));

			pGame->Move(position);
		}

		// game over
		pGame->DisplayBoard();
		pGame->DisplayResult();


		// prompt to play again (or quit)
		char input = ' ';
		while (input != 'Y' && input != 'y')
		{
			std::cout << "Would you like to play again? (y/n): ";
			cin >> input;

			if (input == 'N' || input == 'n') return 0; // quit
		}
	}
}

