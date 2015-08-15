#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>
/*
This is my header class for the Gameboard. I decided to make a seperate class
for the gameboard to be able to control the program easier. It controls the 
presentation of the board including the default class and destructor
to set up the board and delete the memory after. There is a class to reset
the board if the user wanted to play again, and a class to actually print the board.
I made two classes for the user to make a move and one to validate if its an option
that is possible or not. The last one is a class that would check to see if the game 
was won or not and stop it if someone won.

*/
using namespace std;
class GameBoard
{
private:
	string **board;
	int spacesFilled;
	bool gameWon;

public:
	const static int BOARD_LENGTH = 3;
	const static char X = 'X';
	const static char Y = 'Y';

	GameBoard();
	~GameBoard();
	
	void reset();
	void printBoard();
	void placeToken(int, char);
	void placeTokenAgain(char);

	bool checkVictory();
};

#endif