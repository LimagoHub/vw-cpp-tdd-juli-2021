#pragma once
#include <exception>

class repository_exception :
    public std::exception
{
public:
	repository_exception()
	{
	}

	repository_exception(char const* _Message)
		: exception(_Message)
	{
	}

	repository_exception(char const* _Message, int i)
		: exception(_Message, i)
	{
	}

	repository_exception(exception const& _Other)
		: exception(_Other)
	{
	}
};

