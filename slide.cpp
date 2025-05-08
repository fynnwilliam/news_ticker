#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

auto slide_once = [slide = false] mutable { return slide ^= true; };

template <typename Func = decltype(slide_once)>
auto slide_until(
    std::string note, const size_t width = 75, Func keep_sliding = slide_once
) {
  using namespace std::chrono_literals;

  note.append(width, ' ');
  while (keep_sliding()) {
    const char* n_ptr = note.data();
    for (auto size = note.size(), index = 0zu; index < size; ++index) {
      auto s = index >= width ? std::string_view{++n_ptr, width}
                              : std::string_view{n_ptr, index};
      std::cout << std::setw(width) << s << '\r' << std::flush;
      std::this_thread::sleep_for(150ms);
    }
  }
};

const auto slide = [](std::string note, const size_t width = 75) {
  return slide_until(note, width);
};

const auto message = [](int argc, char** argv) {
  std::string message;
  for (int index{1}; index < argc; ++index)
    message.append(argv[index]).append(" ");

  return message;
};

int main(int argc, char** argv) {
  auto note = argc > 1
                  ? message(argc, argv)
                  : "hi, welcome to C++ London | CppCon | ACCU | C++ on Sea";
  slide(note);
}