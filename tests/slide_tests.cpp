#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "slide.h"

TEST_CASE("get_slide() should always return an lvalue of  the same slide object")
{
    slide& a = slide::get_slide();
    slide& b = slide::get_slide();
    
    SECTION("a should be equal to b")
    {
        REQUIRE(&a == &b);
    }
}

TEST_CASE("message() should return a const lvalue of the class data member, message_")
{
    
}

TEST_CASE("message(int, char**) should assign the pointed to object to message_")
{
    
}

TEST_CASE("message(std::string) should move the value parsed to it to message_")
{
    
} 