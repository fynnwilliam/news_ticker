#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void clear_line()
{
    std::cout << "\u001b[2K";
}

int main(int argc, char** argv)
{
	using namespace std::chrono_literals;

	std::string slide = argv[1];
	
	slide.insert(slide.begin(), 5, ' ');

	for(int i = 0; i < 5; ++i)
	{
		std::rotate(slide.begin(), slide.begin() + 1, slide.end());
		std::cout << slide + '\r' << std::flush;
		std::this_thread::sleep_for(1000ms);
	}
	
	clear_line();
}