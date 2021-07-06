#include "personen_service_impl_test.h"

#include "../PersonenSericeProjectNeu/personen_service_exception.h"


#include "../../Tag2_01PersonenServiceProjekt/Tag2_01PersonenServiceProjekt/repository_exception.h"


using namespace testing;
TEST_F(personen_service_impl_test, speichern_firstname_too_short_throws_personenserviceexception)
{
	person invalid_person;
	invalid_person.set_vorname("J");

	EXPECT_THROW(object_under_test.speichern(invalid_person), personen_service_exception);
}

TEST_F(personen_service_impl_test, speichern_lastname_too_short_throws_personenserviceexception)
{
	person invalid_person;
	invalid_person.set_nachname("D");

	EXPECT_THROW(object_under_test.speichern(invalid_person), personen_service_exception);
}

TEST_F(personen_service_impl_test, speichern_antipath_throws_personenserviceexception)
{
	person antipath_person;
	
	ON_CALL(unsympathen_service_mock_, is_unsympath(_)).WillByDefault(Return(true));
	EXPECT_THROW(object_under_test.speichern(antipath_person), personen_service_exception);
}

TEST_F(personen_service_impl_test, speichern_repository_exception_throws_personenserviceexception)
{
	person valid_person;
	repository_exception ex("Dummy");
	ON_CALL(unsympathen_service_mock_, is_unsympath(_)).WillByDefault(Return(false));
	ON_CALL(personen_reporitory_mock_, insert(_)).WillByDefault(Throw(ex));
	EXPECT_THROW(object_under_test.speichern(valid_person), personen_service_exception);
}

TEST_F(personen_service_impl_test, speichern_unexpected_item_is_thrown_throws_personenserviceexception)
{
	person valid_person;
	ON_CALL(unsympathen_service_mock_, is_unsympath(_)).WillByDefault(Return(false));
	ON_CALL(personen_reporitory_mock_, insert(_)).WillByDefault(Throw("Upps"));
	EXPECT_THROW(object_under_test.speichern(valid_person), personen_service_exception);
}

TEST_F(personen_service_impl_test, speichern_happy_day_person_is_passed_to_repo)
{
	person valid_person;
	valid_person.set_vorname("Max");
	valid_person.set_nachname("Mustermann");
	EXPECT_CALL(unsympathen_service_mock_, is_unsympath("Max")).WillOnce(Return(false));
	EXPECT_CALL(personen_reporitory_mock_, insert(Eq(valid_person))).Times(1);

	object_under_test.speichern(valid_person);
}