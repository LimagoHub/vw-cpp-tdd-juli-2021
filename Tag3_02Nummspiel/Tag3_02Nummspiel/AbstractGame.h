#pragma once
#include "Game.h"
#include "GamePlayer.h"
#include <algorithm>
#include <functional>

#include "Writer.h"

namespace vw
{
	namespace games
	{
		template <class SCENE, class TURN>
		class AbstractGame : public Game
		{
		private:
			std::vector<std::reference_wrapper<GamePlayer<SCENE, TURN> > > players;
			GamePlayer<SCENE, TURN>* activePlayer;
			TURN activeTurn;
			Writer& writer;
			void execute_turns() // Integration
			{
				for (auto& player : players)
				{
					prepare_and_execute_single_turn(player);
				}
			}

			void prepare_and_execute_single_turn(GamePlayer<SCENE, TURN>& player) // Operation
			{
				activePlayer = &player;
				execute_turn_for_activePlayer();
			}

			void execute_turn_for_activePlayer() // Integration
			{
				if (!initialize_turn()) return;

				invoke_player_turn();

				terminate_turn();
			}

			bool initialize_turn() // Operation
			{
				prepare_turn();
				return !is_game_over();
			}

			void invoke_player_turn() // Operation
			{
				do
				{
					activeTurn = activePlayer->do_turn(scene_);
				}
				while (check_activeTurn_invalid());
			}

			void terminate_turn() // Integration
			{
				update_scene();
				check_losing();
			}

			bool check_activeTurn_invalid() // operation
			{
				if (is_turn_valid()) return false;

				print( "ungueltiger Zug \n" );
				return true;
			}

			void check_losing() const // operation
			{
				
				if (is_game_over()) print(activePlayer->get_name().append(" hat verloren.\n"));
			}

			void print(std::string message) const
			{
				writer.write(message);
			}

		protected:
			
			SCENE scene_;

			virtual bool is_game_over() const = 0;

			virtual void update_scene() = 0;

			virtual bool is_turn_valid() = 0;

			virtual void prepare_turn()
			{
				// do nothing here. can be overridden.
			}

			TURN get_active_turn() const
			{
				return activeTurn;
			}

			const auto& get_players() const
			{
				return players;
			}

		public:

			AbstractGame(Writer & writer):writer(writer)
			{
				
			}
			void play() override
			{
				
				while (!is_game_over()) execute_turns();
			}

			void add_player(GamePlayer<SCENE, TURN>& player)
			{
				players.push_back(std::ref(player));
			}

			void remove_player(GamePlayer<SCENE, TURN>& player)
			{
				auto iterator = std::remove_if(players.begin(), players.end(),
				                               [&player](GamePlayer<SCENE, TURN>& storedPlayer)
				                               {
					                               return storedPlayer.get_name() == player.get_name();
				                               });
				players.erase(iterator, players.end());
			}
		};
	}
}
