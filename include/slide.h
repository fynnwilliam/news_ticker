#pragma once

#include <string>

class slide
{
private:
    std::string message_;
    constexpr static int sw_{75};
    
    slide() = default;
    
    std::string rotate(std::size_t count) const;
    void clear_line() const;
    bool screen_full(int count) const;
    bool more_text() const;
    bool less_text() const;

public:
    slide(slide const&) = delete;
    slide& operator=(slide const&) = delete;

    static slide& get_slide();
    
    std::string const& message() const { return message_; }
    void message(int argc, char** argv);
    void message(std::string s);
    void display() const;
};
