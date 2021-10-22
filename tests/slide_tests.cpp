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

TEST_CASE("testing our constructor for the counter class")
{
    counter count{};
    
    SECTION("the address of count should not be nullptr")
    {
        REQUIRE(&count != nullptr);
    }
    
    SECTION("the data member, count_ must be assigned zero")
    {
        REQUIRE(!count.data());
    }
}

TEST_CASE("data() member function should return the current value held by count_")
{
    counter count{};
    count.set(10);
    
    SECTION("count.data() should return 10")
    {
        REQUIRE(count.data() == 10);
    }
}

TEST_CASE("pre-increment operator should return an lvalue of the updated count_")
{
    counter count{};
    auto& a = ++count;
    auto  b = (++count).data();
    
    SECTION("address of count should be the same as a")
    {
        REQUIRE(&count == &a);
    }
    
    SECTION("count.data() should return the same value as b")
    {
        REQUIRE(count.data() == b);
    }
    
    SECTION("a.data() should return the same value as b")
    {
        REQUIRE(a.data() == b);
    }
    
    SECTION("count.data() should be euqal to 2")
    {
        REQUIRE(count.data() == 2);
    }
}

TEST_CASE("post-increment operator should return the value of count_ prior to the update")
{
    counter count{};
    
    auto const& a = count++;
    auto        b = count.data();
    auto        c = count++.data();
    
    SECTION("address of count should be different from the address of a")
    {
        REQUIRE(&count != &a);
    }
    
    SECTION("count++.data() should return the previous version of count")
    {
        REQUIRE(b == c);
    }
    
    SECTION("b should be equal to 1")
    {
        REQUIRE(b == 1);
    }
    
    SECTION("the value in count should be more than 0")
    {
        REQUIRE(count.data());
    }
    
    SECTION("count.data() should be greater than c")
    {
        REQUIRE(count.data() > c);
    }
    
    SECTION("the difference between count.data() and b should be 1")
    {
        REQUIRE(count.data() - b == 1);
    }
}

TEST_CASE("pre-decrement operator should return and lvalue of the updated count_")
{
    counter count{};
    count.set(3);
    
    auto& a = --count;
    auto  b = a.data();
    auto  c = (--count).data();
    auto  d = (--count).data();
    auto  e = (--count).data();
    
    SECTION("address of count should be the same as a")
    {
        REQUIRE(&count == &a);
    }
    
    SECTION("b should be equal to 2")
    {
        REQUIRE(b == 2);
    }
    
    SECTION("c should be equal to 1")
    {
        REQUIRE(c == 1);
    }
    
    SECTION("d should be euqal to 0")
    {
        REQUIRE(d == 0);
    }
    
    SECTION("further decrement on an object with value == 0 should return zero")
    {
        REQUIRE(e == 0);
    }
}

TEST_CASE("post-decrement operator should return the value of count_ prior to the update")
{
    
}

TEST_CASE("reset() member function should assign zero to the count_ data member")
{
    
}