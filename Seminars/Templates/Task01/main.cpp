#include "Set.h"
#include <iostream>

int main()
{
    Set<int> s1,s2;
    s1.add(2);
    s1.add(3);
    s2.add(1);
    s2.add(5);
    s2.add(2);
    std::cout << s1 << std::endl;
    Set<int> s3, s4,s5;
    s3=s1+s2;
    s4 = s1*s2;
    s5 = s2-s1;

    std::cout << std::boolalpha<<( s1==s2) << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout <<s5 << std::endl;

    //write
    std::string fileName;
    getline(std::cin,fileName);
    std::ofstream output(fileName);
    s2.write(output);
    

    //read
    Set<int> s6;
    std::string fName;
    getline(std::cin, fName);
    std::ifstream input(fName);
    s6.read(input);
    std::cout << s6 <<std::endl;


    return 0;
}