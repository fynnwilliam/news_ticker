cmake_minimum_required(VERSION	3.21.3)

set(CMAKE_CXX_STANDARD 20)

project(slide)

add_executable(slide src/main.cpp src/slide.cpp)
add_executable(tests tests/slide_tests.cpp src/slide.cpp)

target_include_directories(slide PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(slide PRIVATE -g)
