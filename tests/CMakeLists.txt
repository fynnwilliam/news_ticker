add_executable(tests slide_tests.cpp)
target_link_libraries(tests PRIVATE slide_)

if(MSVC)
  target_compile_options(test PRIVATE /O2 /W4)
else()
  target_compile_options(tests PRIVATE -O3)
endif()
