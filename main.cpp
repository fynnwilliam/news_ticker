#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <string>

std::string extract_message(int argc, char** argv)
{
    std::string s;
    
    for (int i{1}; i < argc; ++i)
        s.append(argv[i]).append(" ");
    
    return s;    
}

void clear_line()
{
    std::cout << "\u001b[2K";
}

std::string rotate(std::string const& s, int count)
{
    return count > s.size() && s.size() < 70
           ?
           s.substr(0, count).append(count - s.size(), ' ')
           :
           s.substr(0, count);
}

int main(int argc, char** argv)
{
	using namespace std::chrono_literals;

	std::string slide = extract_message(argc, argv);

	for(int i = 0; i < 100; ++i)
	{
		std::cout << std::setw(70) << rotate(slide, i) + '\r' << std::flush;
		std::this_thread::sleep_for(100ms);
	}
	
	clear_line();
}
