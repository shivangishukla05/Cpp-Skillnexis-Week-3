#include <iostream>
using namespace std;

class Student {
    string name;
    int marks;

public:
    Student(string n, int m) {
        name = n;
        marks = m;
        cout << "Constructor called" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    ~Student() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Student s("Rahul", 85);
    s.display();

    return 0;
}
