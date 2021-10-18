#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>

int main(int argc, char** argv)
{
	using namespace std::chrono_literals;

	std::string slide = argv[1];
	
	slide.insert(slide.begin(), 5, ' ');

	std::system("clear -x");

	for(int i = 0; i < 10'000; ++i)
	{
		std::rotate(slide.begin(), slide.begin() + 1, slide.end());
		std::cout << slide + '\r' << std::flush;
		std::this_thread::sleep_for(1000ms);
	}

    std::system("clear -x");
}