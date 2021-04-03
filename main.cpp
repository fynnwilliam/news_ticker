#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>
#include <vector>


int main()
{
	using namespace std::chrono_literals;
	
	std::system("clear");

	std::string user_input {" welcome to the morning show...    "};
	std::vector<char> banner(user_input.begin(), user_input.end());

	for(int i = 0; i < 10000; i++)
	{
		std::rotate(banner.begin(), banner.begin() + 1, banner.end());
		std::copy(banner.begin(), banner.end(), std::ostreambuf_iterator<char>(std::cout));
		std::cout << std::flush;
		std::this_thread::sleep_for(1000ms);
		std::system("clear");
	}

	return 0;
}
