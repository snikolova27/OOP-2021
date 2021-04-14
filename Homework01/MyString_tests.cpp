#include "catch2.hpp"
#include "MyString.h"

TEST_CASE("Testing the setter function")
{
    SECTION("Testing with non-empty string")
    {
        MyString str;
        str.setString("hello");
        REQUIRE(strcmp(str.c_str(), "hello") == 0);
        REQUIRE(str.size() == 5);
    }
    SECTION("Testing with an empty string")
    {
        MyString str;
        str.setString("");
        REQUIRE(strcmp(str.c_str(), "") == 0);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str;
        str.setString(nullptr);
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
}
TEST_CASE("Testing the constructors and getter functions")
{
    SECTION("Testing the default constructor")
    {
        MyString str;
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }

    SECTION("Testing the parameter constructor with non-null parameters")
    {
        MyString str("hello");
        REQUIRE(strcmp(str.c_str(), "hello") == 0);
        REQUIRE(str.size() == 5);
    }
    SECTION("Testing the parameter constructor with an empty string")
    {
        MyString str("");
        REQUIRE(strcmp(str.c_str(), "") == 0);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing the parameter constructor with a null pointer")
    {
        MyString str(nullptr);
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing the copy constructor with non-null parameter")
    {
        MyString str("hello");
        MyString str2(str);
        REQUIRE(str2.size() == 5);
        REQUIRE(strcmp(str2.c_str(), "hello") == 0);
    }
    SECTION("Testing the copy constructor with an empty string")
    {
        MyString str("");
        MyString str2(str);
        REQUIRE(strcmp(str2.c_str(), "") == 0);
        REQUIRE(str2.size() == 0);
    }
    SECTION("Testing the copy constructor with a null pointer")
    {
        MyString null;
        MyString str(null);
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
}
TEST_CASE("Testing at function and [] operator")
{
    MyString str("hello");
    SECTION("Testing at function with valid position")
    {
        REQUIRE(str.at(2) == 'l');
    }
    SECTION("Testing at function with out of range position")
    {
        REQUIRE_THROWS(str.at(6));
    }
    SECTION("Testing the  [] operator with valid postion")
    {
        REQUIRE(str[2] == 'l');
    }
}
// not testing the [] operator,front, back functions with an invalid position
// because we have an assertion in the functions for the position

TEST_CASE("Testing the front function")
{
    SECTION("Testing with a valid postion")
    {
        MyString str("hello");
        REQUIRE(str.front() == 'h');
    }
}
TEST_CASE("Testing the back function")
{
    SECTION("Testing with a valid position")
    {
        MyString str("hello");
        REQUIRE(str.back() == 'o');
    }
}
TEST_CASE("Testing the empty function")
{
    SECTION("Testing with a non-null value")
    {
        MyString str("hello");
        REQUIRE(str.empty() == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        REQUIRE(str.empty() == 1);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        REQUIRE(str.empty() == 1);
    }
}
TEST_CASE("Testing the clear function")
{
    SECTION("Testing with a non-null value")
    {
        MyString str("hello");
        str.clear();
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        str.clear();
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        str.clear();
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
}
TEST_CASE("Testing the push back function")
{
    SECTION("Testing with a non-empty string")
    {
        MyString str("hell");
        str.push_back('o');
        REQUIRE(str.back() == 'o');
        REQUIRE(str.size() == 5);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        str.push_back('A');
        REQUIRE(str.back() == 'A');
        REQUIRE(str.size() == 1);
    }
    SECTION("Testing with a nullptr")
    {
        MyString str(nullptr);
        str.push_back('A');
        REQUIRE(str.back() == 'A');
        REQUIRE(str.size() == 1);
    }
}
TEST_CASE("Testing the pop back function")
{
    SECTION("Testing with a non-empty string")
    {
        MyString str("hello");
        str.pop_back();
        REQUIRE(str.size() == 4);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        str.pop_back();
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        str.pop_back();
        REQUIRE(str.size() == 0);
    }
}
TEST_CASE("Testing the = opertor")
{
    SECTION("Testing with non-null value")
    {
        MyString str("hello");
        MyString str2;
        str2 = str;
        REQUIRE(str2.size() == 5);
        REQUIRE(strcmp(str2.c_str(), "hello") == 0);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        MyString str2;
        str2 = str;
        REQUIRE(str2.size() == 0);
        REQUIRE(strcmp(str2.c_str(), "") == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        MyString str2;
        str2 = nullptr;
        REQUIRE(str2.size() == 0);
        REQUIRE(str2.c_str() == nullptr);
    }
}
TEST_CASE("Testing += character operator")
{
    SECTION("Testing with a non-empty string")
    {
        MyString str("hell");
        str += 'o';
        REQUIRE(str.back() == 'o');
        REQUIRE(str.size() == 5);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        str += 'A';
        REQUIRE(str.back() == 'A');
        REQUIRE(str.size() == 1);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        str += 'A';
        REQUIRE(str.back() == 'A');
        REQUIRE(str.size() == 1);
    }
}
TEST_CASE("Testing the += string operator")
{
    SECTION("Testing with a non-empty string")
    {
        MyString str("hello, ");
        MyString str2("world");
        str += str2;
        REQUIRE(str.size() == 12);
        REQUIRE(strcmp(str.c_str(), "hello, world") == 0);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("hello, ");
        MyString str2("");
        MyString str3("hey");
        str += str2;
        str2 += str3;
        REQUIRE(str.size() == 7);
        REQUIRE(strcmp(str.c_str(), "hello, ") == 0);
        REQUIRE(str2.size() == 3);
        REQUIRE(strcmp(str2.c_str(), "hey") == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str("hello");
        MyString str2(nullptr);
        MyString str3("hey");
        str += str2;
        str2 += str3;
        REQUIRE(str.size() == 5);
        REQUIRE(strcmp(str.c_str(), "hello") == 0);
        REQUIRE(str2.size() == 3);
        REQUIRE(strcmp(str2.c_str(), "hey") == 0);
    }
}
// not testing the + character and + string operators
// because the corresponding += operators have been tested already

TEST_CASE("Testing the < operator")
{
    SECTION("Testing with a non-empty string")
    {
        MyString str("abc");
        MyString str2("def");
        REQUIRE((str < str2) == 1);
    }
    SECTION("Testing with equal strings")
    {
        MyString str("abc");
        MyString str2("abc");
        REQUIRE((str < str2) == 0);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("abc");
        MyString str2("");
        REQUIRE((str < str2) == 0);
        REQUIRE((str2 < str) == 1);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str("abc");
        MyString str2(nullptr);
        REQUIRE((str < str2) == 0);
        REQUIRE((str2 < str) == 1);
    }
}
TEST_CASE("Testing the == operator")
{
    SECTION("Testing with an non-empty string")
    {
        MyString str("abc");
        MyString str2("def");
        REQUIRE((str == str2) == 0);
        MyString str3("abc");
        REQUIRE((str == str3) == 1);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("abc");
        MyString str2("");
        REQUIRE((str == str2) == 0);
        MyString str3("");
        REQUIRE((str2 == str3) == 1);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str("abc");
        MyString str2(nullptr);
        REQUIRE((str == str2) == 0);
        MyString str3(nullptr);
        REQUIRE((str2 == str3) == 1);
    }
}
