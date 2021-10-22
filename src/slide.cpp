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
    return count_.data() >= sw_;
}

bool slide::more_text() const
{
    return message().size() >= sw_;
}

std::string slide::rotate() const
{
    std::string const& s = message_;
    std::string temp =  screen_full() ? s.substr(count_.data() - (sw_ - 1), sw_) : s.substr(0, count_.data());
    
    return screen_full() && more_text()    ? temp.append(sw_ - temp.size(),' ')            :
           count_.data() > temp.size() - 1 ? temp.append(count_.data() - temp.size(), ' ') : temp;
}

void slide::clear_line() const
{
    std::cout << "\u001b[2K";
}

void slide::display()
{
    using namespace std::chrono_literals;

	for ( ; count_.data() < message_.size() + sw_; ++count_)
	{   
	    std::cout << std::setw(sw_) << rotate() + '\r' << std::flush;
	    std::this_thread::sleep_for(300ms);
	}
	
	count_.reset();
	clear_line();
}