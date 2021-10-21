#include "slide.h"

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

slide& slide::get_slide()
{
    static slide s{};
    
    return s;
}

void slide::message(int argc, char** argv)
{
    for (int i{1}; i < argc; ++i)
        message_.append(argv[i]).append(" ");
}

void slide::message(std::string s)
{
    message_ = std::move(s);
}

std::string slide::rotate(std::size_t count) const
{
    std::string const& s = message_;
    return count >= 70 && s.size() >= 70 && s.substr(count - 69).size() < 70
           ?
           s.substr(count - 69).append(70 - s.substr(count - 69).size(),' ')
           :
           count >= 70 && s.size() >= 70
           ?
           s.substr(count - 69, 69)
           :
           count >= 70 && s.size() < 70
           ?
           s.substr(count - 69).append(count - s.size(), ' ')
           :
           count > s.size() - 1 && s.size() < 70
           ?
           s.substr(0, count).append(count - s.size(), ' ')
           :
           s.substr(0, count);
}

void slide::clear_line() const
{
    std::cout << "\u001b[2K";
}

void slide::display() const
{
    using namespace std::chrono_literals;

    for(std::size_t i{}; i < message_.size() + 70; ++i)
	{
		std::cout << std::setw(70) << rotate(i) + '\r' << std::flush;
		std::this_thread::sleep_for(300ms);
	}
	
	clear_line();
}