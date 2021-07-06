#pragma once
#include <ostream>
#include <string>

class person
{
private:
	std::string id;
	std::string vorname;
	std::string nachname;
public:
	person();

	[[nodiscard]] std::string get_id() const
	{
		return id;
	}

	void set_id(const std::string& id)
	{
		this->id = id;
	}

	[[nodiscard]] std::string get_vorname() const
	{
		return vorname;
	}

	void set_vorname(const std::string& vorname)
	{
		this->vorname = vorname;
	}

	[[nodiscard]] std::string get_nachname() const
	{
		return nachname;
	}

	void set_nachname(const std::string& nachname)
	{
		this->nachname = nachname;
	}


	friend bool operator==(const person& lhs, const person& rhs)
	{
		return lhs.id == rhs.id
			&& lhs.vorname == rhs.vorname
			&& lhs.nachname == rhs.nachname;
	}

	friend bool operator!=(const person& lhs, const person& rhs)
	{
		return !(lhs == rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const person& obj)
	{
		return os
			<< "id: " << obj.id
			<< " vorname: " << obj.vorname
			<< " nachname: " << obj.nachname;
	}
};

