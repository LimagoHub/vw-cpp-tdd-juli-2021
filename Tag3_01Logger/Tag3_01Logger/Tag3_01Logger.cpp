// Tag3_01Logger.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>


#include "ConsolenAppender.h"
#include "Logger.h"

int main()
{
	ConsolenAppender appender;
    Logger logger{appender};
	logger.log("Hallo");
}

