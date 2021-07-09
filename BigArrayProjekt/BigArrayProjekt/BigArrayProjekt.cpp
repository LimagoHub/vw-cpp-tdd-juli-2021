// Tag2_03BigArray.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//




#include "ArrayService.h"
int main()
{

	int* data = new int[MAX_ARRAY_SIZE];

	ArrayService service;

	service.fillArrayParallelWithRandomNumbers(data);

	delete[] data;
	return 0;
}

