#include <iostream>
#include <vector>

int main()
{
    std::vector<int> collection;
    unsigned int cntOfElements;

    std::cout << "How many elements will you add to the collection? \n";
    std::cin >> cntOfElements;
    std::cin.ignore();

    for (int i = 0; i < cntOfElements; i++)
    {
        int num;
        std::cin >> num;
        collection.push_back(num);
    }

    for (std::vector<int>::const_iterator i = collection.begin(); i != collection.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}