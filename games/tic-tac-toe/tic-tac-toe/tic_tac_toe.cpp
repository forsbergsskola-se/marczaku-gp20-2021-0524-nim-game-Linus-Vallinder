#include "tic_tac_toe.h"
#include <iostream>

using namespace std;

int start()
{
	cout << "Enter the amount of human players.\n Enter [1] to play against AI\n Enter [2] to play multiplayer" << endl;
	int amount{};

	while (amount < 1 || amount > 2)
	{
		cin >> amount;

		if (amount < 1 || amount > 2)
		{
			cout << "Incorrect input. Try again." << endl;
		}
	}

	if (amount == 1)
	{
		cout << "\nYou have chosen to play against an AI." << endl;
	}
	else if(amount == 2)
	{
		cout << "\nYou have chosen to play against another player." << endl;
	}

	return amount;
}

int getPlayerInput(char currentPlayer)
{
	int number = 0;

	cout << "Select an empty field on the board." << endl;
	cout << "Enter a number from 1 to 9: ";

	while (number < 1 || number > 9)
	{
		cin >> number;

		if (number < 1 || number > 9)
		{
			cout << "Incorrect input. Try again." << endl;
		}
	}

	return number;
}

void displayBoard(char* board, char currentPlayer)
{
	if (currentPlayer == 'X')
	{
		cout << "Current Turn: ";
		cout << "Player One [X]";
	}
	else
	{
		cout << "Current Turn: ";
		cout << "Player Two [O]";
	}
	cout << " " << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

	cout << "     |     |     " << endl << endl;
}

bool tic_tac_toe::checkForWin()
{
	return false;
} 

int main()
{
	int playerAmount = start();

	char board[9] = {' ', ' ', ' ',' ', ' ', ' ' ,' ', ' ', ' ' };

	char playerOne = 'X';
	char playerTwo = 'O';
	char currentPlayer = playerOne;

	while (true)
	{
		if (playerAmount == 1 && currentPlayer == playerOne)
		{
			displayBoard(board, currentPlayer);
			int box = getPlayerInput(currentPlayer);

			if (board[box - 1] == ' ')
			{
				board[box - 1] = 'X';
				currentPlayer = playerTwo;
			}
			else
			{
				cout << "Please try again." << endl;
				displayBoard(board, currentPlayer);
				int box = getPlayerInput(currentPlayer);
			}
		}
		else if (playerAmount == 1 && currentPlayer == playerTwo)
		{
			displayBoard(board, currentPlayer);
			int box = rand() % 9;
			if (board[box - 1] == ' ')
			{
				board[box - 1] = 'O';
				currentPlayer = playerOne;
			}
			else
			{
				int box = rand() % 9;
			}
		}
	}
}