cmake_minimum_required(VERSION	3.21.3)

set(CMAKE_CXX_STANDARD 20)

project(slide)

add_library(slide_ src/slide.cpp)

add_executable(slide src/main.cpp)
add_executable(tests tests/slide_tests.cpp)

target_link_libraries(slide PRIVATE slide_)
target_link_libraries(tests PRIVATE slide_)

target_include_directories(slide_ PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(slide  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(tests  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(slide PRIVATE -O3)
target_compile_options(tests PRIVATE -O3)