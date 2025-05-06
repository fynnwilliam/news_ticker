#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

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

int main() { slide("testing slide..."); }