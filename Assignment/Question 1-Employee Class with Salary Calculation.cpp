#include <iostream>
using namespace std;

class Employee {
    string name;
    int id;
    double basicSalary;

public:
    Employee(string n, int i, double salary) {
        name = n;
        id = i;
        basicSalary = salary;
    }

    double calculateSalary() {
        double hra = basicSalary * 0.20;
        double da = basicSalary * 0.10;
        double pf = basicSalary * 0.12;
        return basicSalary + hra + da - pf;
    }

    void display() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Net Salary: " << calculateSalary() << endl;
    }
};

int main() {
    Employee e("Rahul Sharma", 101, 40000);
    e.display();

    return 0;
}
