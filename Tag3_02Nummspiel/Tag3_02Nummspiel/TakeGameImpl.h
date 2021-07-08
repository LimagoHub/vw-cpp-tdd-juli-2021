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
			
			void execute_turns()  // Integration
			{
				for(auto &player: players)
				{
					
				}
				
			}

			void human_turn()
			{
				if (is_game_over()) return;


				while (true)
				{
					std::cout << "Es gibt " << stones_ << " Steine. Bitte nehmen Sie 1,2 oder 3: ";
					std::cin >> zug;
					if (zug >= 1 && zug <= 3) break;
					std::cout << "ungültiger Zug " << std::endl;
				}
				terminate_turn("human");
			}

			void computer_turn()
			{
				if (is_game_over()) return;

				const int zuege[] = { 3, 1, 1, 2 };
				zug = zuege[stones_ % 4];
				std::cout << "Computer nimmt " << zug << " Steine." << std::endl;

				terminate_turn("Computer");
			}
			
			

			void terminate_turn(std::string player) // Integration
			{
				update_scene();
				check_losing(player);
			}

			

		void check_losing(std::string player) const
		{
			if (is_game_over()) std::cout << player << " hat verloren." << std::endl;
		}

		void update_scene() // operation
		{
			stones_ -= zug;
		}
		protected:
			bool is_game_over() const // operation
			{
				return stones_ < 1;
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
