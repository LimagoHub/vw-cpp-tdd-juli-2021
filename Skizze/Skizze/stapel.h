#pragma once

class stapel
{
private:
	bool empty{ true };
public:
	bool is_empty()
	{
		return empty;
	}

	void push(int i)
	{
		empty = false;
	}
};