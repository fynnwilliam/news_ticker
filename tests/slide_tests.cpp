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
    slide& s = slide::get_slide();
    
    std::string const& first_msg = s.message();
    std::string const& second_msg = s.message();

    SECTION("s.message() should return an empty string")
    {
        REQUIRE(s.message().size() == 0);
    }
    
    SECTION("the size of first_msg should be equal to the size of second_msg")
    {
        REQUIRE(first_msg.size() == 0);
        REQUIRE(second_msg.size() == 0);
    }
    
    SECTION("address of first_msg should be equal to the address of second_msg")
    {
        REQUIRE(&first_msg == &second_msg);
    }
}

TEST_CASE("message(int, char**) should assign the pointed to object to message_")
{
    int argc{8};
    
    char argv0[] = "./slide";
    char argv1[] = "Hello";
    char argv2[] = "everyone,";
    char argv3[] = "you";
    char argv4[] = "are";
    char argv5[] = "welcome";
    char argv6[] = "to";
    char argv7[] = "CppCon!";
    
    char* argx[] = {argv0, argv1, argv2, argv3, argv4, argv5, argv6, argv7};
    char** argv  = argx;
    
    slide& s = slide::get_slide();
    s.message(argc, argv);
    
    SECTION("calling s.message() should return the same message argv points to")
    {
        REQUIRE(s.message() == "Hello everyone, you are welcome to CppCon!");
    }
}

TEST_CASE("message(std::string) should move the value parsed to it, to message_")
{
    slide& s = slide::get_slide();
    
    s.message("getting ready for the next session...");
    
    REQUIRE(s.message() == "getting ready for the next session...");
}

TEST_CASE("slide::rotate() should only return a sub-string  of the message_")
{
    slide& s = slide::get_slide();
    s.message("The next session starts in ten minutes");
    s.counter(10);
    
    std::string message_before_rotate = s.message();
    
    std::string rotated_version       = s.rotate();
    
    std::string message_after_rotate = s.message();
    
    SECTION("the original message in the slide object should not change after a call to rotate()")
    {
        REQUIRE(message_before_rotate == message_after_rotate);
    }
    
    SECTION("rotate should return a string object")
    {
        REQUIRE(rotated_version == s.message().substr(0, s.counter()));
    }
}

TEST_CASE("slide::display() should alwayas reset the counter object to zero at the end of the for loop")
{
}