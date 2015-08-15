#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "Game Board.h"

using namespace std;

//Default class used to set up the board.

GameBoard::GameBoard()
{
	board = new string*[BOARD_LENGTH];
	for(int ndx = 0; ndx < BOARD_LENGTH; ndx++)
		board[ndx] = new string[BOARD_LENGTH];
	reset();
}

//Deconstructor made to release the memory that was allocated.
GameBoard::~GameBoard()
{
	for(int ndx = 0; ndx < BOARD_LENGTH; ndx++)
		delete [] board[ndx];
	delete [] board;
	board = NULL;
}
//clears the board and gets a new board
void GameBoard::reset()
{
	board[0][0] = "| 1 |";
	board[0][1] = "| 2 |";
	board[0][2] = "| 3 |";

	board[1][0] = "| 4 |";
	board[1][1] = "| 5 |";
	board[1][2] = "| 6 |";

	board[2][0] = "| 7 |";
	board[2][1] = "| 8 |";
	board[2][2] = "| 9 |";

	spacesFilled = 0;
	gameWon = false;

	printBoard();
	return;
}
//places the correct shape in the box that the user chooses
void GameBoard::placeToken(int loc, char token)
{
	switch(loc)
	{
	case 0://Exit
		break;
	case 1:
		if(board[0][0] != "| 1 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[0][0] = "| X |";
			else
				board[0][0] = "| O |";
			spacesFilled++;
		}
		break;
	case 2:
		if(board[0][1] != "| 2 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[0][1] = "| X |";
			else
				board[0][1] = "| O |";
			spacesFilled++;
		}
		break;
	case 3:
		if(board[0][2] != "| 3 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[0][2] = "| X |";
			else
				board[0][2] = "| O |";
			spacesFilled++;
		}
		break;
	case 4:
		if(board[1][0] != "| 4 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[1][0] = "| X |";
			else
				board[1][0] = "| O |";
			spacesFilled++;
		}
		break;
	case 5:
		if(board[1][1] != "| 5 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[1][1] = "| X |";
			else
				board[1][1] = "| O |";
			spacesFilled++;
		}
		break;
	case 6:
		if(board[1][2] != "| 6 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[1][2] = "| X |";
			else
				board[1][2] = "| O |";
			spacesFilled++;
		}
		break;
	case 7:
		if(board[2][0] != "| 7 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[2][0] = "| X |";
			else
				board[2][0] = "| O |";
			spacesFilled++;
		}
		break;
	case 8:
		if(board[2][1] != "| 8 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[2][1] = "| X |";
			else
				board[2][1] = "| O |";
			spacesFilled++;
		}
		break;
	case 9:
		if(board[2][2] != "| 9 |")
			placeTokenAgain(token);
		else
		{
			if(token == 'X')
				board[2][2] = "| X |";
			else
				board[2][2] = "| O |";
			spacesFilled++;
		}
		break;
	default:
		placeTokenAgain(token);
		break;
	}
	return;
}
//checks if the placement is valid and prints it to user
void GameBoard::placeTokenAgain(char token)
{
	cout << "Invalid move\nChoose your move: ";
	int move;
	cin >> move;
	placeToken(move, token);
	return;
}
//clears the screen and prints the board with how many spaces are left
void GameBoard::printBoard()
{
	system("cls");
	for(int ndx = 0; ndx < BOARD_LENGTH; ndx++)
	{
		for(int mdx = 0; mdx < BOARD_LENGTH; mdx++)
		{
			cout << board[ndx][mdx];
		}
		cout << endl;
	}

	cout << "Spaces remaining: " << (pow(BOARD_LENGTH, 2) - spacesFilled) << endl;
	return;
}

//checks the board for all possible winning combinations 
bool GameBoard::checkVictory()
{
	if(board[0][0] == board[0][1]  &&  board[0][0] == board[0][2]) //Horizontal Row 1
		gameWon = true;
	else if(board[1][0] == board[1][1]  &&  board[1][0] == board[1][2]) //Horizontal Row 2
		gameWon = true;
	else if(board[2][0] == board[2][1]  &&  board[2][0] == board[2][2]) //Horizontal Row 3
		gameWon = true;

	else if(board[0][0] == board[1][1]  &&  board[0][0] == board[2][2]) //Diagonal, Top left->bottom right
		gameWon = true;
	else if(board[2][0] == board[1][1]  &&  board[2][0] == board[0][2]) //Diagonal, Bottom left->top right
		gameWon = true;

	else if(board[0][0] == board[1][0]  &&  board[0][0] == board[2][0]) //Vertical Column 1
		gameWon = true;
	else if(board[0][1] == board[1][1]  &&  board[0][1] == board[2][1]) //Vertical Column 2
		gameWon = true;
	else if(board[0][2] == board[1][2]  &&  board[0][2] == board[2][2]) //Vertical Column 3
		gameWon = true;
	return gameWon;
}