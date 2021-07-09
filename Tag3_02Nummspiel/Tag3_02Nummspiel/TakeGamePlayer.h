#pragma once
#include <string>

#include "GamePlayer.h"

class TakeGamePlayer: public GamePlayer<int, int>
{
public:
	std::string get_name() const override = 0;

	/// <summary>
	///  bla,bla
	/// </summary>
	/// <param name="stones"></param>
	/// <returns></returns>
	int do_turn(const int & stones) const override = 0;

	
	
};

