#pragma once
#include "../Tag3_02Nummspiel/AbstractGame.h"
#include "DummyClassesForTest.h"
#include "../Tag3_02Nummspiel/Writer.h"

class MyAbstractGameDummy : public vw::games::AbstractGame<DummyScene, DummyTurn>
{
public:
	bool game_over{ false };
	bool is_valid{ true };

	MyAbstractGameDummy(Writer& writer)
		: AbstractGame<DummyScene, DummyTurn>(writer)
	{
	}

protected:
	[[nodiscard]] bool is_game_over() const override { return game_over; }

	void update_scene() override {}

	bool is_turn_valid() override { return is_valid; }
}; 
