#include "List.h"
#include "Order.h"

int main()
{
    List<int> l1;
    l1.add(2);
    l1.add(4);
    l1.add(6);
    l1.add(2);

    std::cout << l1.getSize() << std::endl;
    std::cout << l1[0] << std::endl;
    std::cout << l1[1] << std::endl;
    std::cout << l1[2] << std::endl;
    l1.write("output.txt");

    // List<int> l2;
    // l2.read("input.txt");
    // l2.write("list2.txt");
    //  std::cout << l2[0] << std::endl;
    
    OrderedList<int> l3;
    l3.add(10);
    l3.add(2);
    l3.add(4);

    l3.print();

    return 0;
}