#pragma once
#include "Game.h"
#include "GamePlayer.h"

namespace vw
{
	namespace games {
		template<class SCENE, class TURN>
		class AbstractGame : public Game
		{
		private:
			void execute_turns()  // Integration
			{
				for (auto& player : players)
				{
					prepare_and_execute_single_turn(player);
				}

			}
		
		protected:
			std::vector<std::reference_wrapper<GamePlayer<SCENE,TURN>>> players;
			virtual bool is_game_over() const = 0;
		public:
			void play() override
			{
				while (!is_game_over())	execute_turns();

			}
		};
	}
}

