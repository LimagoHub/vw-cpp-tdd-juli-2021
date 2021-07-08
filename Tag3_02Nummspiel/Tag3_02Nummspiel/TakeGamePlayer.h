#pragma once
#include <string>

class TakeGamePlayer
{
public:
	virtual std::string get_name() = 0;
	virtual int do_turn(int stones) = 0;
	
};

