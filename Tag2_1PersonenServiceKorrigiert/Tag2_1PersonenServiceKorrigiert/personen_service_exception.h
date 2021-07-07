#pragma once
#include <exception>

class personen_service_exception :
    public std::exception
{
public:

	personen_service_exception()
	{
	}

	personen_service_exception(char const* _Message)
		: exception(_Message)
	{
	}

	personen_service_exception(char const* _Message, int i)
		: exception(_Message, i)
	{
	}

	personen_service_exception(exception const& _Other)
		: exception(_Other)
	{
	}
};

