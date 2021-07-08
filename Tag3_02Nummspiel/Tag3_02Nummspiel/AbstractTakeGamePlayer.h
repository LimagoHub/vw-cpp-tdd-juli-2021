#pragma once
#include "TakeGamePlayer.h"
class AbstractTakeGamePlayer :
    public TakeGamePlayer 
{
private :
	std::string name;
public:
	AbstractTakeGamePlayer(std::string name) :name(name){}


	std::string get_name() override
	{
		return name;
	}


	
};

