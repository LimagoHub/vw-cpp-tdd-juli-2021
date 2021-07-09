#pragma once
#include <gtest/gtest.h>
#include "../Tag3_02Nummspiel/AbstractGame.h"
#include "../Tag3_02Nummspiel/ComputerPlayer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DummyClassesForTest.h"
#include "GamePlayerMock.h"
#include "MyAbstractGameDummy.h"
#include "WriterMock.h"

using namespace testing;



class AbstractGameTest: public Test
{
protected:

	WriterMock writer_mock;
	GamePlayerMock game_player_mock;
	MyAbstractGameDummy object_under_test{ writer_mock };


	void SetUp() override
	{
		object_under_test.add_player(game_player_mock);
		EXPECT_CALL(game_player_mock, get_name()).Times(AnyNumber()).WillRepeatedly(Return("MockPlayer"));
	}
};
