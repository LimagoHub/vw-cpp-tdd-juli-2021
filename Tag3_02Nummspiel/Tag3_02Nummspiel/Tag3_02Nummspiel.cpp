// Tag3_02Nummspiel.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>



#include "GameClient.h"
#include "TakeGameImpl.h"

int main()
{
	vw::games::TakeGameImpl game;
	client::GameClient client(game);
	client.go();
}

