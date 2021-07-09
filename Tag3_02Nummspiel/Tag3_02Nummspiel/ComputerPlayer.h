#pragma once
#include <iostream>

#include "AbstractTakeGamePlayer.h"
class ComputerPlayer :
    public AbstractTakeGamePlayer
{
	const int zuege[4] = { 3, 1, 1, 2 };
public:
	ComputerPlayer(const std::string& name)
		: AbstractTakeGamePlayer(name)
	{
	}
	

	int do_turn(const int & stones) const override
	{
		int zug = zuege[stones % 4];
		std::cout << "Computer nimmt " << zug << " Steine." << std::endl;
		return zug;
	}
};

