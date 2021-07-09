#include "../Tag3_02Nummspiel/AbstractGame.h"
#include "../Tag3_02Nummspiel/ComputerPlayer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace testing;

class DummyScene
{
};

class DummyTurn
{
};

class GamePlayerMock : public GamePlayer<DummyScene, DummyTurn>
{
public:
	MOCK_METHOD(std::string, get_name, (), (const, override));
	MOCK_METHOD(DummyTurn, do_turn, (const DummyScene& scene), (const, override));
};

class WriterMock : public Writer
{
public:
	MOCK_METHOD(void, write, (std::string), ( override));
};

bool game_over;
bool is_valid;


TEST(AbstractGameTest, play_success)
{
	game_over = false;

	class MyAbstractGameDummy : public vw::games::AbstractGame<DummyScene, DummyTurn>
	{
	public:

		MyAbstractGameDummy(Writer& writer)
			: AbstractGame<DummyScene, DummyTurn>(writer)
		{
		}

	protected:
		bool is_game_over() const override 	{return game_over;}

		void update_scene() override {}

		bool is_turn_valid() override { return true; }
	};

	WriterMock writer_mock;
	GamePlayerMock game_player_mock;
	MyAbstractGameDummy object_under_test{writer_mock};

	object_under_test.add_player(game_player_mock);
	EXPECT_CALL(game_player_mock, do_turn(_)).WillOnce([](DummyScene d)
	{
		game_over = true;
		return DummyTurn{};
	});

	EXPECT_CALL(game_player_mock, get_name()).WillOnce(Return("MockPlayer"));


	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren.\n")));

	object_under_test.play();
}

TEST(AbstractGameTest, play_mogeln)
{
	game_over = false;
	is_valid = false;

	class MyAbstractGameDummy : public vw::games::AbstractGame<DummyScene, DummyTurn>
	{
	public:

		MyAbstractGameDummy(Writer& writer)
			: AbstractGame<DummyScene, DummyTurn>(writer)
		{
		}

	protected:
		bool is_game_over() const override { return game_over;}

		void update_scene() override {}

		bool is_turn_valid() override { return is_valid; }
	};

	WriterMock writer_mock;
	GamePlayerMock game_player_mock;
	MyAbstractGameDummy object_under_test{writer_mock};

	object_under_test.add_player(game_player_mock);

	EXPECT_CALL(game_player_mock, do_turn(testing::_)).WillRepeatedly([](DummyScene d)
	{
		game_over = true;
		return DummyTurn{};
	});


	EXPECT_CALL(game_player_mock, get_name()).WillOnce(Return("MockPlayer"));


	EXPECT_CALL(writer_mock, write(Eq("ungueltiger Zug \n"))).WillOnce([](std::string s) { is_valid = true; });
	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren.\n")));
	object_under_test.play();
}
