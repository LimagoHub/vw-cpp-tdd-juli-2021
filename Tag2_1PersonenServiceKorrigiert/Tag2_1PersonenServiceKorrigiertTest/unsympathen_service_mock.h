#pragma once


#include "../Tag2_01PersonenServiceProjekt/unsympathen_service.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
class unsympathen_service_mock : public unsympathen_service {
public:
	MOCK_METHOD(bool, is_unsympath, (std::string), (override));
	
};

