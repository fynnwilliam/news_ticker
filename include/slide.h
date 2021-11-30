#pragma once

#include <string>

class slide
{
private:
    std::string message_;
    std::size_t counter_{};
    constexpr static int screen_width_{75};

    std::string rotate() const;
    void reset_counter() noexcept;
    void clear_line() const noexcept;
    bool is_screen_full() const noexcept;
    int sw() const noexcept;
    
    slide() = default;
    slide(slide const&) = delete;
    slide& operator=(slide const&) = delete;

public:
    static slide& get_slide() noexcept;
    
    std::string const& message() const noexcept { return message_; }
    std::string& message() noexcept;
    void message(int argc, char** argv) noexcept;
    void message(std::string s) noexcept;
    void display();
    void counter(std::size_t) noexcept;
    std::size_t counter() const noexcept;
};