#include "personen_service_impl.h"

personen_service_impl::personen_service_impl(personen_repository& personen_repository)
	: personen_repository_(personen_repository)
{
}


void personen_service_impl::speichern(person& p)
{
}

void personen_service_impl::speichern(std::string vorname, std::string nachname)
{
}

std::optional<person> personen_service_impl::findeEinzelnePerson(std::string id)
{
	return std::optional<person>();
}
