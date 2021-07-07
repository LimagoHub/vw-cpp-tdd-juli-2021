#pragma once
#include <iostream>

#include "Game.h"

namespace vw
{
	namespace games
	{
		class TakeGameImpl :
			public Game
		{
		private:
			int stones_;
			bool gameover_;

			
			void execute_turns()
			{
				human_turn();
				computer_turn();
				
			}


			void human_turn()
			{
				int zug;

				while (true)
				{
					std::cout << "Es gibt " << stones_ << " Steine. Bitte nehmen Sie 1,2 oder 3: ";
					std::cin >> zug;
					if (zug >= 1 && zug <= 3) break;
					std::cout << "ungültiger Zug " << std::endl;
				}
				stones_ -= zug;
			}

			void computer_turn()
			{
				const int zuege[] = {3, 1, 1, 2};
				if (stones_ == 1)
				{
					std::cout << "Du hast nur Glueck gehabt " << std::endl;
					gameover_ = true;
					return;
				}

				if (stones_ <= 0)
				{
					std::cout << "Du Loser! " << std::endl;
					gameover_ = true;
					return;
				}
				int zug = zuege[stones_ % 4];
				std::cout << "Computer nimmt " << zug << " Steine." << std::endl;
				stones_ -= zug;
			}

		public:
			TakeGameImpl()
			{
				stones_ = 23;
				gameover_ = false;
			}


			void play() override
			{
				while (! gameover_)	execute_turns();
				
			}
		};
	}
}
