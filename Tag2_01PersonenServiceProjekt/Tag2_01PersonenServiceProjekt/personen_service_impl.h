#pragma once
#include "personen_repository.h"
#include "personen_service.h"
class personen_service_impl :
    public personen_service
{
private :
	personen_repository& personen_repository_;
	void speichern_impl(person& p);
	void check_person(person& p);
	void validate(person& p);
	void business_check(person& p);
public:

	personen_service_impl(personen_repository& personen_repository);


	/*
	 * Vorname weniger als 2 Zeichen -> PSE
	 * Nachname weniger als 2 Zeichen -> PSE
	 *
	 * Attila ist nicht erwünscht -> PSE
	 *
	 * Exception in underliying service -> PSE
	 *
	 * person is passed to repo
	 * 
	 */
	void speichern(person& p) override;
	void speichern(std::string vorname, std::string nachname) override;
	std::optional<person> findeEinzelnePerson(std::string id) override;
};

