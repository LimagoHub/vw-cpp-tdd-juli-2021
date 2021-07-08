// Tag3_02Nummspiel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>



#include "ComputerPlayer.h"
#include "GameClient.h"
#include "HumanPlayer.h"
#include "TakeGameImpl.h"

int main()
{
	vw::games::TakeGameImpl game;
	ComputerPlayer cp{ "Maschine" };
	HumanPlayer hp{ "Mensch" };
	game.add_player(hp);
	game.add_player(cp);

	client::GameClient client(game);
	client.go();
}

