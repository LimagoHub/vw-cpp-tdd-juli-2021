// Tag3_02Nummspiel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>


#include "ComputerPlayer.h"
#include "ConsolenWriter.h"
#include "GameClient.h"
#include "HumanPlayer.h"
#include "TakeGameImpl.h"

int main()
{
	ConsolenWriter console_writer;
	vw::games::TakeGameImpl game{console_writer};

	auto player1 = HumanPlayer{"Spieler"};
	auto player2 = ComputerPlayer{"Computer"};

	game.add_player(player1);
	game.add_player(player2);

	client::GameClient client(game);
	client.go();
}
