#include "slide.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

slide& slide::get_slide() noexcept {
  static slide s{};
  return s;
}

void slide::message(int argc, char** argv) noexcept {
  for (int i{1}; i < argc; ++i)
    message_.append(argv[i]).append(" ");

  if (message_.size())
    message_.pop_back();
}

void slide::message(std::string s) noexcept { message() = std::move(s); }

bool slide::is_screen_full() const noexcept { return counter() >= sw(); }

std::string& slide::message() noexcept { return message_; }

int slide::sw() const noexcept { return screen_width_; }

std::string slide::rotate() const {
  std::string const& s = message();
  std::string temp = is_screen_full() ? s.substr(counter() - (sw() - 1), sw())
                                      : s.substr(0, counter());

  return is_screen_full()          ? temp.append(sw() - temp.size(), ' ')
         : counter() > temp.size() ? temp.append(counter() - temp.size(), ' ')
                                   : temp;
}

void slide::clear_line() const noexcept { std::cout << "\u001b[2K"; }

void slide::counter(std::size_t c) noexcept { counter_ = c; }

std::size_t slide::counter() const noexcept { return counter_; }

void slide::reset_counter() noexcept { counter_ = 0uz; }

void slide::display() {
  using namespace std::chrono_literals;

  for (; counter() < message_.size() + sw(); ++counter_) {
    std::cout << std::setw(sw()) << rotate() + '\r' << std::flush;
    std::this_thread::sleep_for(150ms);
  }

  reset_counter();
  clear_line();
}