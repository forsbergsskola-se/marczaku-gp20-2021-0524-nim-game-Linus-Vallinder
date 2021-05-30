#pragma once
class tic_tac_toe
{
	public:
		void start();
		int getPlayerInput(char currentPlayer);
		void displayBoard(char[9], char);
		void displayBoard();
		bool checkForWin(char[9], char);
};

int main();
