#pragma once

#include <string>
#include "counter.h"

class slide
{
private:
    std::string message_;
    counter count_{};
    constexpr static int sw_{75};

    std::string rotate() const;
    void clear_line() const;
    bool screen_full() const;
    bool more_text() const;
    
    slide() = default;
    slide(slide const&) = delete;
    slide& operator=(slide const&) = delete;

public:
    static slide& get_slide();
    
    std::string const& message() const { return message_; }
    void message(int argc, char** argv);
    void message(std::string s);
    void display();
};
