#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "functions.h"
#include <cstring>

TEST_CASE("Check if the letter is in upper case", "[letter]")
{
    char lower = 'a';
    char upper = 'A';

    SECTION("Test with letter in lower case")
    {
        REQUIRE(toUpper(lower) == 'A');
    }
    SECTION("Test with letter in upper case")
    {
        REQUIRE(toUpper(upper) == 'A');
    }
}

TEST_CASE("Check if the function for an average grade works correctly", "[grade]")
{
    Student newStudent;
    newStudent.grades[5];
    newStudent.grades[0].grade = 5.25;
    newStudent.grades[1].grade = 4.75;
    newStudent.grades[2].grade = 5.4;
    newStudent.grades[3].grade = 6;
    newStudent.grades[4].grade = 3.85;

    REQUIRE(newStudent.avgGrade() == 5.05);
}

TEST_CASE("Check if all initial letters of  first 2 names are capitalisied after using the function firstLastName", "[names]")
{
    Student newStudent;
    newStudent.name[0] = 'S';
    newStudent.name[1] = 'o';
    newStudent.name[2] = 'n';
    newStudent.name[3] = 'y';
    newStudent.name[4] = 'a';
    newStudent.name[5] = ' ';
    newStudent.name[6] = 'N';
    newStudent.name[7] = 'i';
    newStudent.name[8] = 'k';
    newStudent.name[9] = 'o';
    newStudent.name[10] = 'l';
    newStudent.name[11] = 'o';
    newStudent.name[12] = 'v';
    newStudent.name[13] = 'a';
    newStudent.name[14] = ' ';
    newStudent.name[15] = 'N';
    newStudent.name[16] = 'i';
    newStudent.name[17] = 'k';
    newStudent.name[18] = 'o';
    newStudent.name[19] = 'l';
    newStudent.name[20] = 'o';
    newStudent.name[21] = 'v';
    newStudent.name[22] = 'a';

    SECTION("Test")
    {
        REQUIRE(strcmp("Sonya Nikolova", newStudent.firstLastName()) == 0);
    }
}