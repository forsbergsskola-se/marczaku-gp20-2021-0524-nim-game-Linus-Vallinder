#include "converter.h"
#include <iostream>

using namespace std;

void toBinary(int number)
{
	cout << "Decimal Number:";
	cout << number << endl;

	cout << "Binary Number:";
	if (number == 0)
	{
		cout << "0b0";
	}

	int binaryAmount = 0;
	int binary[32];

	for (int i = 0; number > 0; i++)
	{
		binary[i] = number % 2;
		number = number / 2;
		binaryAmount++;
	}

	cout << "0b";
	for (int i = binaryAmount - 1; i >= 0; i--)
	{
		cout << binary[i];
	}
}

int input()
{
	int number = 0;

	while (true)
	{
		cout << "Enter a positive number: ";
		cin >> number;

		if (number >= 0)
		{
			return number;
		}
	}
}

int main()
{
	int number = input();
	toBinary(number);
}