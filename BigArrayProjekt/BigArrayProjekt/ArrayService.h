#pragma once

#include <iostream>
#include <climits>
#include <chrono>
#include <thread>
#include <random>
#include <vector>
#include <future>
const int MAX_ARRAY_SIZE = INT32_MAX >> 4;

class ArrayService
{
	const unsigned processor_count{ std::thread::hardware_concurrency() };
	int* data;
	int processor;

	
	static void fill_array_worker(int* data, int start, int end) {
		std::random_device rn;
		std::mt19937 engine{ rn() };


		std::uniform_int_distribution<int> dice{ INT32_MIN, INT32_MAX };
		
		for (int i = start; i < end; i++)
			data[i] = dice(engine);
	}

	static int maxFinderWorker(int* data, int start, int end) {
		int max = data[start++];
		for (int i = start; i < end; i++)
			max = data[i] > max ? data[i] : max;
		return max;
	}




	void start_parallel_processing()
	{
		std::vector<std::thread> v;
		start_workers(v);
		

		await_termination(v);
	}


	void start_workers(std::vector<std::thread> &v)
	{
		for (int thread = 0; thread < processor; thread++) {
			start_single_worker(v, thread);
		}
	}

	void start_single_worker(std::vector<std::thread>& v, int thread)
	{
		v.emplace_back((std::thread(fill_array_worker, data, thread * (MAX_ARRAY_SIZE / processor), (thread + 1) * (MAX_ARRAY_SIZE / processor)));
	}


	static void await_termination(std::vector<std::thread> &v) 
	{
		for (auto& t : v)
		{
			if (t.joinable())
				t.join();
		}
	}

	void time_measure_decorator(std::function<void(void)> function_to_measure)
	{
		std::cout << "\nMessung mit " << processor << " Threads." << std::endl;
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		
		function_to_measure();
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::duration<double> dur = end - start;
		std::cout << "Duration: " << dur.count() << std::endl << "#########################" << std::endl << std::endl;
	}
public:

	

	void fillArrayParallelWithRandomNumbers(int *data)
	{
		this->data = data;
		for (processor = 1; processor <= processor_count + 1; processor++) {
			time_measure_decorator([this]() {start_parallel_processing(); });
		}
	}
};

