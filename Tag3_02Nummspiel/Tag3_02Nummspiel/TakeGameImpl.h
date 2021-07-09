#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


#include "AbstractGame.h"
#include "Game.h"
#include "TakeGamePlayer.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

namespace vw
{
	namespace games
	{
		class TakeGameImpl :
			public AbstractGame<int, int>
		{
		protected:
			bool is_turn_valid() override // operation
			{
				return (get_active_turn() >= 1 && get_active_turn() <= 3);
			}

			bool is_game_over() const override // operation
			{
				return scene_ < 1 || get_players().empty();
			}

			void update_scene() override // operation
			{
				scene_ -= get_active_turn();
			}

		public:
			TakeGameImpl(Writer & writer):AbstractGame<int, int>(writer)
			{
				scene_ = 23;
			}
		};
	}
}
