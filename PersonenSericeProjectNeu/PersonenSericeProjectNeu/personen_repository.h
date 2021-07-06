#pragma once
#include <optional>
#include <vector>

#include "person.h"

class personen_repository
{
public:
	virtual void insert(const person& person) = 0;
	virtual bool update(const person& person) = 0;
	virtual bool remove(const person& person) = 0;
	virtual bool remove(std::string id) = 0;
	virtual std::optional<person> find_by_id(std::string id) = 0;
	virtual std::vector<person> find_all() = 0;
};

