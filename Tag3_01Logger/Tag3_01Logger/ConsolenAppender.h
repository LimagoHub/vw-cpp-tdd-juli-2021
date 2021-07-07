#pragma once
#include "Appender.h"
class ConsolenAppender :
    public Appender
{
public:

	void write(std::string message) override;
};

