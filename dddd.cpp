#include <iostream>

struct Employee
{
    short id;
    int age;
    double salary;
};

void printInformation(Employee employee)
{
    std::cout << "ID: " << employee.id << "\n";
    std::cout << "Age: " << employee.age << "\n";
    std::cout << "Salary: " << employee.salary << "\n";
}

int main()
{
    Employee john = { 21, 27, 28.45 };
    Employee james = { 22, 29, 19.29 };

    // Выводим информацию о John-е
    printInformation(john);

    std::cout << "\n";

    // Выводим информацию о James-е
    printInformation(james);

    return 0;
}
