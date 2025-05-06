cmake_minimum_required(VERSION 3.21.3)
set(CMAKE_CXX_STANDARD 23)
project(slide)

add_executable(slide slide.cpp)

if(MSVC)
  target_compile_options(slide PRIVATE /W4 /O2)
else()
  target_compile_options(slide PRIVATE -Wall -Wextra -O3)
endif()
