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

bool slide::screen_full() const
{
    return counter_ >= sw_;
}

bool slide::more_text() const
{
    return message().size() >= sw_;
}

std::string slide::rotate() const
{
    std::string const& s = message_;
    std::string temp =  screen_full() ? s.substr(counter_ - (sw_ - 1), sw_) : s.substr(0, counter_);
    
    return screen_full()           ? temp.append(sw_ - temp.size(),' ')       :
           counter() > temp.size() ? temp.append(counter_ - temp.size(), ' ') : temp;
}

void slide::clear_line() const
{
    std::cout << "\u001b[2K";
}

void slide::counter(std::size_t i)
{
    counter_ = i;
}

std::size_t slide::counter() const
{
    return counter_;
}

void slide::reset_counter()
{
    counter_ = 0;
}

void slide::display()
{
    using namespace std::chrono_literals;

	for ( ; counter_ < message_.size() + sw_; ++counter_)
	{   
	    std::cout << std::setw(sw_) << rotate() + '\r' << std::flush;
	    std::this_thread::sleep_for(300ms);
	}
	
	reset_counter();
	clear_line();
}