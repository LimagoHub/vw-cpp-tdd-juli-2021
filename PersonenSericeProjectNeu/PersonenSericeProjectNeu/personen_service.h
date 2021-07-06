#pragma once
#include <optional>

#include "person.h"

class personen_service
{
public:
	virtual void speichern(person& p) = 0;
	virtual void speichern(std::string vorname, std::string nachname) = 0;
	virtual std::optional<person> findeEinzelnePerson(std::string id) = 0;
};

