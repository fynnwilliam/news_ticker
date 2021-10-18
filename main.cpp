#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>

int main()
{
	using namespace std::chrono_literals;

	std::string slide;

	std::cout << "please enter a message for the slide: ";
	std::getline(std::cin, slide);
	
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