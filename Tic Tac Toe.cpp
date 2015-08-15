#include <iostream>

#include "Game Board.h"
#include "Tic Tac Toe.h"

using namespace std;

int main()
{
	//shows the splash of the program
	displaySplash();
	//creates board
	GameBoard board;
	//prints gameboard
	int choice = 0;
	board.printBoard();
	//loop to continue asking user for input 
	do
	{
		//asks first player for input, which chooses if he ends game or where he places move
		cout << "Player 1 choose your move(Enter 0 to quit): ";
		cin >> choice;
		if(choice == 0)
			break;
		board.placeToken(choice, board.X);
		board.printBoard();
		if(board.checkVictory())
			playAgain(board);
		else
		{
		//asks second player for input, which chooses if he ends game or where he places move
			cout << "Player 2 choose your move(Enter 0 to quit): ";
			cin >> choice;
			board.placeToken(choice, board.Y);
			board.printBoard();
			if(board.checkVictory())
				playAgain(board);
		}
		//continues the loop until user exits or someone wins
	}	while(choice != 0 && board.checkVictory() == false);

	return 0;
}