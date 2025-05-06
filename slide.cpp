#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

const auto slide = [](std::string note, const size_t width = 75) {
  using namespace std::chrono_literals;

  note.append(width, ' ');
  const char* n_ptr = note.data();
  for (auto size = note.size(), index = 0zu; index < size; ++index) {
    auto s = index >= width ? std::string_view{++n_ptr, width}
                            : std::string_view{n_ptr, index};
    std::cout << std::setw(width) << s << '\r' << std::flush;
    std::this_thread::sleep_for(150ms);
  }
};

const auto message = [](int argc, char** argv) {
  std::string message;
  for (int index{1}; index < argc; ++index)
    message.append(argv[index]).append(" ");

  return message;
};

int main(int argc, char** argv) {
  auto note = argc > 1 ? message(argc, argv)
                       : "hi, welcome to C++ London | CppCon | ACCU | CppOnSea";
  slide(note);
}