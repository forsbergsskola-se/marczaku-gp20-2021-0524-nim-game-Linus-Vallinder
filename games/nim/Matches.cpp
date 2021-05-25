#include "Matches.h"

void Matches::Remove(int amount)
{
	matchAmount -= amount;
}

int Matches::GetAmount() const
{
	return matchAmount;
}

std::string Matches::GetDisplayString()
{
	std::string matches;

	for (int i = 0; i < GetAmount(); i++)
	{
		matches += "|";
	}

	return matches;
}
