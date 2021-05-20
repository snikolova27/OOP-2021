#include "Registration.h"
#include <cstring>


//helper functions
bool Registration::isLetter(char c)
{
    return (c >= 'A' && c <= 'Z');
}
bool Registration::isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
bool Registration::isValid(const char *reg) 
{
    std::size_t len = strlen(reg);

    return (len >= MIN_REG_LEN && len <= MAX_REG_LEN) && (isLetter(reg[len - 1]) && isLetter(reg[len - 2])) &&
           (isDigit(reg[len - 3]) && isDigit(reg[len - 4]) && isDigit(reg[len - 5]) && isDigit(reg[len - 6]) && isDigit(reg[len - 7])) &&
           (len == MIN_REG_LEN || isLetter(reg[len - 8]));
    // len >=7 & len <9
    // само латински букви
    // 1 или 2 букви в началото главни
    // 4 цифри
    // 2 букви главни
}

Registration::Registration(const char *registration)
{
    //validate registration
    try
    {
        if(!this->isValid(registration))
        {
            throw std::invalid_argument("The registartion is not valid. The format is XX####XX or X#####XX");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::size_t len = strlen(registration);
    strcpy(this->registration, registration);
    this->registration[len] = '\0';
 
}

bool Registration::operator==(const Registration &other)
{
    return strcmp(this->registration, other.getRegistration()) == 0;
}
const char *Registration::getRegistration() const
{
    return this->registration;
}