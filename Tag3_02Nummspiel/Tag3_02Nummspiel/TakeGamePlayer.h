#pragma once
#include <string>

#include "GamePlayer.h"

class TakeGamePlayer: public GamePlayer<int, int>
{
public:
	std::string get_name() const override = 0;
	int do_turn(const int & stones) const override = 0;
	
};

