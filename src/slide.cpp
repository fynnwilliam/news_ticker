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

std::string& slide::message() noexcept { return message_; }

std::string slide::rotate() const {
  const bool is_screen_full = counter_ >= screen_width_;
  std::string temp =
      is_screen_full
          ? message_.substr(counter_ - (screen_width_ - 1), screen_width_)
          : message_.substr(0, counter_);

  return is_screen_full ? temp.append(screen_width_ - temp.size(), ' ')
         : counter_ > temp.size() ? temp.append(counter_ - temp.size(), ' ')
                                  : temp;
}

void slide::clear_line() const noexcept { std::cout << "\u001b[2K"; }

void slide::counter(std::size_t c) noexcept { counter_ = c; }

std::size_t slide::counter() const noexcept { return counter_; }

void slide::reset_counter() noexcept { counter_ = 0uz; }

void slide::display() {
  using namespace std::chrono_literals;

  for (auto max = message_.size() + screen_width_; counter_ < max; ++counter_) {
    std::cout << std::setw(screen_width_) << rotate() + '\r' << std::flush;
    std::this_thread::sleep_for(150ms);
  }

  reset_counter();
  clear_line();
}