#include <chrono>
#include <thread>
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <random>
#include <string>
#include <SortingLib.h>

static void checkTimer()
{
	using namespace std::literals::chrono_literals; //fot 1s
	sorting::Timer time("Check");
	std::this_thread::sleep_for(3s);

}

#define SIZE (int)1000
int main()
{

	std::array<int, SIZE>* values = new std::array<int, SIZE>;
	// Seed the random number generator
	std::mt19937 rng(42);  // Use any integer as the seed (e.g., 42)

	// Define a distribution (e.g., uniform distribution between 1 and 100)
	std::uniform_int_distribution<int> distribution(1, SIZE);

	// Generate and print a random number
	int randomNumber = distribution(rng);

	for (auto& val : *values)
	{
		val = randomNumber;
		randomNumber = distribution(rng);
	}
	std::array<int, SIZE>* copy_values = new std::array<int, SIZE>;

	// Using std::copy algorithm to copy the contents
	std::copy(values->begin(), values->end(), copy_values->begin());

	//PrintVal(*values);
	standard_sort(*copy_values);
	std::copy(values->begin(), values->end(), copy_values->begin());
	bubble_sort(*copy_values);
	std::copy(values->begin(), values->end(), copy_values->begin());
	selective_sort(*copy_values);
	std::copy(values->begin(), values->end(), copy_values->begin());
	quick_sort(*copy_values);
	//PrintVal(*values);

	//checkTimer();

	delete values;
	delete copy_values;
	std::cin.get();

}