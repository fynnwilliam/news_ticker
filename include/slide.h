#pragma once

#include <string>

class slide
{
private:
    std::string message_;
    std::size_t counter_{};
    constexpr static int sw_{75};

    std::string rotate() const;
    void reset_counter();
    void clear_line()    const;
    bool screen_full()   const;
    bool more_text()     const;
    
    slide() = default;
    slide(slide const&) = delete;
    slide& operator=(slide const&) = delete;

public:
    static slide& get_slide();
    
    std::string const& message() const { return message_; }
    void message(int argc, char** argv);
    void message(std::string s);
    void display();
    void counter(std::size_t);
    std::size_t counter() const;
};