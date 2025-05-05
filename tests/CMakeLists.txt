find_package(Catch2 3.8.1)

if(NOT CATCH2_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1)
  FetchContent_MakeAvailable(Catch2)
endif()

add_executable(tests slide_tests.cpp)
target_link_libraries(tests PRIVATE slide_ Catch2::Catch2WithMain)

if(MSVC)
  target_compile_options(test PRIVATE /O2 /W4)
else()
  target_compile_options(tests PRIVATE -O3)
endif()
