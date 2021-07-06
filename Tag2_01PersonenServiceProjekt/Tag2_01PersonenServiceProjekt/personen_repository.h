#pragma once
#include <optional>
#include <vector>

#include "person.h"

/// <summary>
/// Was die Klasse macht, nicht wie sie macht
/// </summary>
class personen_repository
{
public:
	/// <summary>
	/// fügt neue Person in Datenbank ein
	/// </summary>
	/// <param name="person">zu speichernde Person</param>
	virtual void insert(const person& person) = 0;
	virtual bool update(const person& person) = 0;
	virtual bool remove(const person& person) = 0;
	virtual bool remove(std::string id) = 0;
	virtual std::optional<person> find_by_id(std::string id) = 0;
	virtual std::vector<person> find_all() = 0;
};

