add_executable(tests slide_tests.cpp)
target_link_libraries(tests PRIVATE slide_)
target_compile_options(tests PRIVATE -O3)