#include <iostream>
#include "Matches.h"
#include "Gamemode.h"

using namespace std;

void DisplayCurrentState(Matches matches, Gamemode gamemode) 
{
	cout << "Amount of matches remaining:" << endl;
	cout << matches.GetAmount() << endl;
	cout << matches.GetDisplayString() << endl;
	cout << "\nRemove 1, 2 or 3 matches by entering the corresponding number:" << endl;
}

int main()
{
	Matches matches;
	Gamemode gamemode;
	
	cout << "Welcome to the game of Nim\n\n Select game mode:\n 1. Player vs AI\n 2. Player vs Player\n" << endl;

	cout << "Select a Select a game mode by entering the corresponding number:" << endl;

	int selectedGamemode;
	cin >> selectedGamemode;

	if (selectedGamemode == 1) {
		gamemode.isPvp = false;
		cout << "\nYou have selected Player vs AI" << endl;
	}
	else if (selectedGamemode == 2) {
		gamemode.isPvp = true;
		cout << "\nYou have selected Player vs AI" << endl;
	}

	while (!gamemode.isGameOver)
	{
		while (gamemode.isPlayerOnesTurn)
		{
			cout << "Player Ones Turn:" << endl;
			DisplayCurrentState(matches, gamemode);

			cin >> gamemode.amount;

			if(gamemode.amount > 0 && gamemode.amount < 4)
			{
				matches.Remove(gamemode.amount);

				if (matches.GetAmount() <= 0)
				{
					gamemode.isGameOver = true;
				}

				gamemode.isPlayerOnesTurn = false;
			}

			if (gamemode.amount < 0 || gamemode.amount > 3) {
				cout << "The input is invalid" << endl;
			}

		}

		while (!gamemode.isPlayerOnesTurn)
		{
			if (gamemode.isPvp) 
			{
				cout << "Player Twos Turn:" << endl;
				DisplayCurrentState(matches, gamemode);

				cin >> gamemode.amount;

				if (gamemode.amount > 0 && gamemode.amount < 4)
				{
					matches.Remove(gamemode.amount);

					if (matches.GetAmount() <= 0)
					{
						gamemode.isGameOver = true;
					}

					gamemode.isPlayerOnesTurn = true;
				}

				if (gamemode.amount < 0 || gamemode.amount > 3) {
					cout << "The input is invalid" << endl;
				}
			}

			if(!gamemode.isPvp)
			{
				cout << "AI's Turn:" << endl;
				DisplayCurrentState(matches, gamemode);

				gamemode.amount = rand() % 3;

				if (gamemode.amount > 0 && gamemode.amount < 4)
				{
					matches.Remove(gamemode.amount);

					if (matches.GetAmount() <= 0)
					{
						gamemode.isGameOver = true;
					}

					gamemode.isPlayerOnesTurn = true;
				}

				if (gamemode.amount < 0 || gamemode.amount > 3) {
					cout << "The input is invalid" << endl;
				}
			}
		}
	}

	if (gamemode.isPlayerOnesTurn) {

		int exit = 0;

		cout << "The Winner is Player One" << endl;
		cout << "\nEnter 0 to exit the game!" << endl;

		cin >> exit;
	}
	else {
		int exit = 0;

		cout << "The Winner is Player Two" << endl;
		cout << "Enter 0 to exit the game!" << endl;

		cin >> exit;
	}
}
