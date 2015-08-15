#pragma once
#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Game Board.h"

using namespace std;

void displaySplash();
void playAgain(GameBoard&);
//prints the header of the program and then times out and clears the screen
void displaySplash()
{
	cout << "---------------------" << endl;
	cout << "-----Tic Tac Toe-----" << endl;
	cout << "---------------------" << endl;

	Sleep(2500);
	system("cls");

	return;
}
//once one of the players has won and the game ends, it
// asks the user if they would like to play again
void playAgain(GameBoard &bd)
{
	cout << "Would you like to play again(Y/N)? ";
	char choice = '\0';
	cin >> choice;
	if(choice == 'Y')
		bd.reset();
	else if(choice == 'y')
		bd.reset();
	else if(choice == 'N')
		;
	else if(choice == 'n')
		;
	else
		playAgain(bd);
	return;
}

#endif