#include "ConsolenAppender.h"


#include <iostream>


void ConsolenAppender::write(std::string message)
{
	std::cout << message << std::endl;
}
