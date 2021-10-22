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
        
    if(message().size()) message_.pop_back();
}

void slide::message(std::string s)
{
    message_ = std::move(s);
}

bool slide::screen_full(int count) const
{
    return count >= sw_;
}

bool slide::more_text() const
{
    return message().size() >= sw_;
}

bool slide::less_text() const
{
    return message().size() <  sw_;
}

std::string slide::rotate(std::size_t count) const
{
    std::string const& s = message_;
    std::string temp =  screen_full(count) ? s.substr(count - (sw_ - 1), sw_) : s.substr(0, count);
    
    return screen_full(count) && more_text()
           ?
           temp.append(sw_ - temp.size(),' ')
           :
           count > s.size() - 1 || screen_full(count) && less_text()
           ?
           temp.append(count - s.size(), ' ')
           :
           temp;
}

void slide::clear_line() const
{
    std::cout << "\u001b[2K";
}

void slide::display() const
{
    using namespace std::chrono_literals;

    for(std::size_t i{}; i < message_.size() + sw_; ++i)
	{
		std::cout << std::setw(sw_) << rotate(i) + '\r' << std::flush;
		std::this_thread::sleep_for(300ms);
	}
	
	clear_line();
}