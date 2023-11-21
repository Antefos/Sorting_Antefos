#include "SortingLib.h"

/*Timer needed to compare different algorithms*/

sorting::Timer::Timer(std::string name = "Unknown")
	:task(name)
{
	startOS = std::chrono::system_clock::now();
	auto start = Time::now();
}
sorting::Timer::~Timer()
{

	endOS = std::chrono::system_clock::now();
	std::chrono::duration<double> durationOS = (endOS - startOS) * 1000.0;

	std::cout << task << " duration was: " << durationOS.count() << "ms" << std::endl;
	/*
	end = Time::now();
	fsec duration = (end - start);
	ms duration_ms = std::chrono::duration_cast<ms>(duration);
	std::cout << "\n" << task << " task time: " << duration.count() << "ms\n";
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Elapsed Time: " << elapsed.count() << " seconds" << std::endl;
	*/
}




