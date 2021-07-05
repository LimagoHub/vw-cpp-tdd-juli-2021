#pragma once
#include <exception>

class stapel_exception :
    public std::exception
{
public:
	stapel_exception()
	{
	}

	stapel_exception(char const* _Message)
		: exception(_Message)
	{
	}

	stapel_exception(char const* _Message, int i)
		: exception(_Message, i)
	{
	}

	stapel_exception(exception const& _Other)
		: exception(_Other)
	{
	}
};

