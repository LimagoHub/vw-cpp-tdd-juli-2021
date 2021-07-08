#pragma once
#include <iostream>
#include <vector>




#include "Game.h"
#include "TakeGamePlayer.h"

namespace vw
{
	namespace games
	{
		class TakeGameImpl :
			public Game
		{
		private:

			std::vector<std::reference_wrapper<TakeGamePlayer>> players;
			
			int stones_;
			int zug;
			TakeGamePlayer* player;
			
			void execute_turns()  // Integration
			{
				for(auto &player: players)
				{
					prepare_and_execute_single_turn(player);
				}
				
			}

			void prepare_and_execute_single_turn(TakeGamePlayer & player_)
			{
				player = &player_;
				execute_single_turn();
			}

			

			void execute_single_turn()
			{
				if (is_game_over()) return;
				invoke_players_turn();
				terminate_turn();
			}

			
			
			void invoke_players_turn()
			{
				// while (actual_turn_is_invalid(player))
				// {
				// 	std::cout << "ungültiger Zug " << std::endl;
				// }

				do
				{
					zug = player->do_turn(stones_);
				} while (is_actual_invalid());
			}

			bool is_actual_invalid() // Command
			{
				if (is_turn_valid()) return false;
				std::cout << "Ungültiger Zug" << std::endl;
				return true;
			}

			bool is_turn_valid() // query
			{
				return zug >= 1 && zug <= 3;
			}

			void terminate_turn() // Integration
			{
				update_scene();
				check_losing();
			}

			

		void check_losing() const
		{
			if (is_game_over()) std::cout << player->get_name() << " hat verloren." << std::endl;
		}

		void update_scene() // operation
		{
			stones_ -= zug;
		}
		protected:
			bool is_game_over() const // operation
			{
				return stones_ < 1 || players.empty();
			}

		public:
			TakeGameImpl()
			{
				stones_ = 23;
				
			}


			void play() override
			{
				while (! is_game_over())	execute_turns();
				
			}

			void add_player(TakeGamePlayer &player)
			{
				players.push_back(std::ref(player));
				
			}

			void remove_player(TakeGamePlayer& player)
			{
				auto iterator =std::remove_if(players.begin(), players.end(), [&](TakeGamePlayer& storedPlayer) {return storedPlayer.get_name() == player.get_name(); });
				players.erase(iterator, players.end());

			}
		};
	}
}
