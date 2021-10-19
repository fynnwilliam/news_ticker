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

std::string rotate(std::string const& s, std::size_t count)
{
    return count > 70 && s.size() >= 70 && s.substr(count - 70, 70).size() < 70
           ?
           s.substr(count - 70, 70).append(70 - s.substr(count - 70, 70).size(),' ')
           :
           count > 70 && s.size() >= 70
           ?
           s.substr(count - 70, 70)
           :
           count > 70 && s.size() < 70
           ?
           s.substr(count - 70, s.size() - count - 70).append(count - s.size(), ' ')
           :
           count > s.size()
           ?
           s.substr(0, count).append(count - s.size(), ' ')
           :
           s.substr(0, count);
}

int main(int argc, char** argv)
{
	using namespace std::chrono_literals;

	std::string slide = extract_message(argc, argv);

	for(std::size_t i = 0; i < slide.size() + 70; ++i)
	{
		std::cout << std::setw(70) << rotate(slide, i) + '\r' << std::flush;
		std::this_thread::sleep_for(100ms);
	}
	
	clear_line();
}
