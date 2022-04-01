#pragma once



#include "gmock/gmock.h"
#include "gtest/gtest.h"
class personen_repository_mock : public personen_repository {
 public:
  MOCK_METHOD(void, insert, (const person& person), (override));
  MOCK_METHOD(bool, update, (const person& person), (override));
  MOCK_METHOD(bool, remove, (const person& person), (override));
  MOCK_METHOD(bool, remove, (std::string id), (override));
  MOCK_METHOD(std::optional<person>, find_by_id, (std::string id), (override));
  MOCK_METHOD(std::vector<person>, find_all, (), (override));
};
