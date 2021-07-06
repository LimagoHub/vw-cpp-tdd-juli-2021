#pragma once
#include "personen_repository_mock.h"
#include "../PersonenSericeProjectNeu/personen_service_impl.h"
#include "gtest\gtest.h"
#include "gmock\gmock.h"

class personen_service_impl_test :
    public testing::Test
{
protected:
	personen_repository_mock personen_reporitory_mock_;

	personen_service_impl object_under_test{ personen_reporitory_mock_ };
};

