#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <random>
#include <string>
/*
This library contains all different sorting algorithms implementations
- Bubble Sort
- Selective Sort
- Quick Sort
*/
namespace sorting {
	template <typename type_T, int size_T>
	void PrintVal(std::array<type_T, size_T>& values);

	/*Timer needed to compare different algorithms*/
	struct Timer
	{
		typedef std::chrono::high_resolution_clock Time;
		typedef std::chrono::milliseconds ms;
		typedef std::chrono::duration<float> fsec;

		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::system_clock::time_point startOS, endOS;
		std::string task;
		Timer(std::string name);
		~Timer();
	};
}
/*
template <typename type_T, int size_T>
void standard_sort(std::array<type_T, size_T>& values);


template <typename type_T, int size_T>
void bubble_sort(std::array<type_T, size_T>& values);

template <typename type_T, int size_T>
void selective_sort(std::array<type_T, size_T>& values);


template <typename type_T, int size_T>
void quick_sort(std::array<type_T, size_T>& values);
*/

/*SORT ALGORITHMS*/
template <typename type_T>
inline void swap(type_T& a, type_T& b) {
	type_T temp = a;
	a = b;
	b = temp;
}

template <typename type_T, int size_T>
void standard_sort(std::array<type_T, size_T>& values) {
	sorting::Timer time("Standard Sorting");

	// if you use the compare predication greater we sort from high to low
	//std::sort(values.begin(), values.end(), std::greater<type_T>());

	std::sort(values.begin(), values.end(), [](type_T a, type_T b)
		{
			return a < b; //if a is less then b will be put in the front
		}
	);
};

template <typename type_T, int size_T>
void bubble_sort(std::array<type_T, size_T>& values) {
	sorting::Timer time("Bubble Sorting");

	for (type_T& value1 : values)
	{
		for (type_T& value2 : values)
		{
			if (value1 < value2)
			{
				swap(value1, value2);
			}
		}
	}
};

template <typename type_T, int size_T>
void selective_sort(std::array<type_T, size_T>& values) {
	sorting::Timer time("Selective Sorting");
	int i, j, min = 0;
	for (i = 0; i < size_T - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size_T; j++)
		{
			if (values[j] < values[min])
				min = j;
		}
		swap(values[i], values[min]);
	}
};
template <typename type_T, int size_T>
int partition_quick(std::array<type_T, size_T>& arr, int left, int right)
{
	//choose the pivot
	type_T pivot = arr[right];
	//Index of smaller element and Indicate
	//the right position of pivot found so far
	int i = left - 1;

	for (int j = left; j <= right; j++)
	{
		//If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			//Increment index of smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return (i + 1);
}

template <typename type_T, int size_T>
void quick(std::array<type_T, size_T>& arr, int left, int right)
{
	// when low is less than high
	if (left < right)
	{
		// pi is the partition return index of pivot

		int pi = partition_quick(arr, left, right);

		//Recursion Call
		//smaller element than pivot goes left and
		//higher element goes right
		quick(arr, left, pi - 1);
		quick(arr, pi + 1, right);
	}
}

template <typename type_T, int size_T>
void quick_sort(std::array<type_T, size_T>& values) {
	sorting::Timer time("Quick Sorting");
	std::mt19937 rng(42);  // Use any integer as the seed (e.g., 42)
	// Define a distribution (e.g., uniform distribution between 1 and 100)
	std::uniform_int_distribution<int> distribution(1, size_T);
	// Generate and print a random number
	int pivot = distribution(rng);
	quick(values, 0, size_T - 1);
};