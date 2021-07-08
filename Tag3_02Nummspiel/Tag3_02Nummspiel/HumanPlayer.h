#pragma once
#include <iostream>

#include "AbstractTakeGamePlayer.h"
class HumanPlayer :
    public AbstractTakeGamePlayer
{
public:
	HumanPlayer(const std::string& name)
		: AbstractTakeGamePlayer(name)
	{
	}


	int do_turn(int stones) override
	{
		int zug;
		std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3: ";
		std::cin >> zug;
		return zug;
	}
};

