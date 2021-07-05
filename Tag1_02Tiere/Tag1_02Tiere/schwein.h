#pragma once
#include <ostream>
#include <string>

class schwein
{
private :
	std::string name;
	int gewicht;

	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}

public:
	schwein(std::string name = "nobody"):gewicht(10)
	{
		set_name(name);
	}


	std::string get_name() const
	{
		return name;
	}

	int get_gewicht() const
	{
		return gewicht;
	}


	void set_name(const std::string& name)
	{
		if (name == "Elsa") throw std::invalid_argument("name ist nicht erlaubt");
		this->name = name;
	}

	void fressen()
	{
		set_gewicht(get_gewicht() + 1);
	}


	friend std::ostream& operator<<(std::ostream& os, const schwein& obj)
	{
		return os
			<< "Schwein name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}
};

