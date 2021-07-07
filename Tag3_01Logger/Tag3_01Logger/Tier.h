#pragma once
class Tier
{

public:
	virtual Tier clone()
	{
		return Tier{};
	}
};

class Hund: public Tier
{
public:

	virtual Hund clone() 
	{
		return Hund{};
	}
};

