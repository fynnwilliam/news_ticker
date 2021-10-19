#pragma once

#include <string>

class slide
{
private:
    std::string message_;
    
    slide() = default;
    std::string rotate(std::size_t count) const;
    void clear_line() const;

public:
    slide(slide const&) = delete;
    slide& operator=(slide const&) = delete;

    static slide& get_slide();
    
    void message(int argc, char** argv);
    void message(std::string s);
    void display() const;
};
