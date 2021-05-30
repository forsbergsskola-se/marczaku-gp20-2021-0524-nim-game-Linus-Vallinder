#pragma once

#include <string>

class Matches
{
	public:
		void Remove(int amount);
		int GetAmount() const;
		std::string GetDisplayString();

	private:
		int matchAmount = 24;
};

