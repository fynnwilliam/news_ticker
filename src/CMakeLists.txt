add_library(slide_ slide.cpp)
target_include_directories(slide_ PUBLIC ../include)

add_executable(slide main.cpp)
target_link_libraries(slide PRIVATE slide_)
target_compile_options(slide PRIVATE -O3)