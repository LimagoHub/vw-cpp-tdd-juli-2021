#pragma once
#include <string>

class Writer
{
public:
	virtual void write(std::string message) = 0;
};

