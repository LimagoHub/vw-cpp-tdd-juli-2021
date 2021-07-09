#include "AbstractGameTest.h"
#include "DummyClassesForTest.h"
#include "GamePlayerMock.h"
#include "WriterMock.h"
#include "../Tag3_02Nummspiel/AbstractGame.h"
#include "../Tag3_02Nummspiel/ComputerPlayer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace testing;










TEST_F(AbstractGameTest, play_success)
{
	
	
	EXPECT_CALL(game_player_mock, do_turn(_)).WillOnce([this](DummyScene d)
	{
			object_under_test.game_over = true;
			return DummyTurn{};
	});

	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren.\n")));

	object_under_test.play();
}

TEST_F(AbstractGameTest, play_mogeln)
{
	
	object_under_test.is_valid = false;

	EXPECT_CALL(game_player_mock, do_turn(_)).WillRepeatedly([this](DummyScene d)
	{
		object_under_test.game_over = true;
		return DummyTurn{};
	});

	EXPECT_CALL(writer_mock, write(Eq("ungueltiger Zug \n"))).WillOnce([this](std::string s) { object_under_test.is_valid = true; });
	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren.\n")));

	object_under_test.play();
}
