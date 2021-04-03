#include <iostream>
#include "Student.h"
#include "University.h"

int main()
{
   
    size_t numberStudents = 3;
    Student* myStudents = new Student[3];
    Student student1("Peter Kolev", "014611XXXX", "82214", 6, 5, 5, 6, 4);
    Student student2("Sonya Nikolova", "015027XXXX", "82213", 5, 6, 5, 5, 6);
    Student student3("Mihail Enev", "014611XXXX", "7....", 6, 5, 6, 5, 6);
    myStudents[0] = student1;
    myStudents[1] = student2;
    myStudents[2] = student3;

    University university1;
    
    university1.createStudents(myStudents, numberStudents);

    university1.printStudents();
    university1.printSizeCapacity();

    Student student4("Maria Radostinova", "015111XXXX", "82208", 6, 5, 5, 5, 5);

    university1 += student4;

    university1.printStudents();
    university1.printSizeCapacity();

    university1 -= student3;

    university1.printStudents();
    university1.printSizeCapacity();

    Student pesho = university1[0];
    Student sonche = university1[1];
    Student mime = university1[2];
    
    std::cout << sonche << mime << pesho;

    delete[] myStudents;

    return 0;
}