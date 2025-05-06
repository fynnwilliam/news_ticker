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

const auto slide = [](std::string msg, const size_t width = 75) {
  using namespace std::chrono_literals;

  msg.append(width, ' ');
  const char* msg_ptr = msg.data();
  for (auto size = msg.size(), index = 0zu; index < size; ++index) {
    auto s = index >= width ? std::string_view{++msg_ptr, width}
                            : std::string_view{msg_ptr, index};
    std::cout << std::setw(width) << s << '\r' << std::flush;
    std::this_thread::sleep_for(150ms);
  }
};

void slide::display() { ::slide(message_, screen_width_); }