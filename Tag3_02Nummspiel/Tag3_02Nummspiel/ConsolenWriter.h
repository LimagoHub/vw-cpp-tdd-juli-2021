#pragma once
#include <iostream>

#include "Writer.h"
class ConsolenWriter :
    public Writer
{
public:
	void write(std::string message) override
	{
		std::cout << message;
	}
};

