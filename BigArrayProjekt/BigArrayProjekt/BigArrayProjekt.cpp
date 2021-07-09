// BigArrayProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <climits>
#include <chrono>
#include <thread>
#include <random>
#include <vector>

const int MAX_ARRAY_SIZE = INT32_MAX >> 4;
const int NUM_OF_PROCESSORS = 16;

void DoSomethingParallel(int x)
{
	
	std::cout << x << "DoSomethingParallel\n";
}

int main()
{
	const auto processor_count = std::thread::hardware_concurrency();
	std::random_device rn;
	std::mt19937 engine{ rn() };
	std::uniform_int_distribution<int> dice{ INT32_MIN, INT32_MAX };
	
    std::cout << "Hello World!\n";

	int* data = new int[MAX_ARRAY_SIZE];
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		data[i] = dice(engine);

	std::thread t1(DoSomethingParallel, 5);
	//t1.detach();
	if(t1.joinable())
		t1.join();
	
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> dur = end - start;
	std::cout << "Duration: " << dur.count() << std::endl << "#########################" << std::endl << std::endl;

	delete[] data;
}

