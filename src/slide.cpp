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

void slide::counter(std::size_t c) noexcept { counter_ = c; }

std::size_t slide::counter() const noexcept { return counter_; }

void slide::reset_counter() noexcept { counter_ = 0uz; }

void slide::display() {
  using namespace std::chrono_literals;

  message_.append(screen_width_, ' ');
  const char* msg_ptr = message_.data();
  for (auto max_counter = message_.size(); counter_ < max_counter; ++counter_) {
    auto s = counter_ >= screen_width_
                 ? std::string_view{++msg_ptr, screen_width_}
                 : std::string_view{msg_ptr, counter_};
    std::cout << std::setw(screen_width_) << s << '\r' << std::flush;
    std::this_thread::sleep_for(150ms);
  }

  reset_counter();
}