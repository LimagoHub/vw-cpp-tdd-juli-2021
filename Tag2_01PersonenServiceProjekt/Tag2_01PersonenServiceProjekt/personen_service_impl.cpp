#include "personen_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"

void personen_service_impl::speichern_impl(person& p)
{
	check_person(p);
	personen_repository_.insert(p);
}

void personen_service_impl::check_person(person& p)
{
	validate(p);
	business_check(p);
}

void personen_service_impl::validate(person& p)
{
	if (p.get_vorname().length() < 2)
		throw personen_service_exception("Vorname zu kurz!");

	if (p.get_nachname().length() < 2)
		throw personen_service_exception("Nachname zu kurz!");
}

void personen_service_impl::business_check(person& p)
{
	if (unsympathen_service_.is_unsympath(p.get_vorname()))
		throw personen_service_exception("UnerwŁnschte Peron!");
}

personen_service_impl::personen_service_impl(personen_repository& personen_repository,unsympathen_service& unsympathen_service)
	: personen_repository_(personen_repository),unsympathen_service_(unsympathen_service)
{
}


void personen_service_impl::speichern(person& p) 
{
	try
	{
		speichern_impl(p);
	}
	catch (const repository_exception& ex)
	{
		throw personen_service_exception("Repository Error");
	}
	catch (const personen_service_exception& ex)
	{
		throw ex;
	}
	catch (...)
	{
		throw personen_service_exception("Unexpected error");
	}
}

void personen_service_impl::speichern(std::string vorname, std::string nachname)
{
	person my_person;
	my_person.set_vorname(vorname);
	my_person.set_nachname(nachname);
	speichern( my_person);
}

std::optional<person> personen_service_impl::findeEinzelnePerson(std::string id)
{
	return std::optional<person>();
}
