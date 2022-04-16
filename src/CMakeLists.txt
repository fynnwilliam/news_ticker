add_library(slide_ slide.cpp)
target_include_directories(slide_ PUBLIC ../include)

add_executable(slide main.cpp)
target_link_libraries(slide PRIVATE slide_)

if(MSVC)
  target_compile_options(slide PRIVATE /W4 /O2)
else()
  target_compile_options(slide PRIVATE -Wall -Wextra -O3)
endif()
