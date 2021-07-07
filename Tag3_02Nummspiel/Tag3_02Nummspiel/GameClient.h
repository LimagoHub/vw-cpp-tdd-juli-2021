#pragma once
#include "Game.h"
namespace client {

	using namespace vw::games;
	
	class GameClient
	{
	private:
		Game& game_;
	public:
		GameClient(Game & game):game_(game){}

		void go()
		{
			game_.play();
		}
		
	};
}

