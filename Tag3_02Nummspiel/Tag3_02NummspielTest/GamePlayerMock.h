#pragma once
#include "DummyClassesForTest.h"
#include "../Tag3_02Nummspiel/GamePlayer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"



class GamePlayerMock : public GamePlayer<DummyScene, DummyTurn>
{
public:
	MOCK_METHOD(std::string, get_name, (), (const, override));
	MOCK_METHOD(DummyTurn, do_turn, (const DummyScene& scene), (const, override));
};
