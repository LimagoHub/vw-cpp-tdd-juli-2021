#pragma once
#include "Appender.h"
#include "iostream"
class Logger
{

private:
	Appender& appender;
public:

	Logger(Appender & appender):appender(appender){}
	void log(std::string message)
	{
		// Komplizierter Code
		const std::string prefix = "Prefix: ";

		appender.write( prefix + message);
		
	}
};

