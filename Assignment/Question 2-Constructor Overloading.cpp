#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
    double marks;

public:
    Student() {
        name = "Unknown";
        age = 0;
        marks = 0;
    }

    Student(string n) {
        name = n;
        age = 0;
        marks = 0;
    }

    Student(string n, int a) {
        name = n;
        age = a;
        marks = 0;
    }

    Student(string n, int a, double m) {
        name = n;
        age = a;
        marks = m;
    }

    void display() {
        cout << name << " " << age << " " << marks << endl;
    }
};

int main() {
    Student s1;
    Student s2("Aman");
    Student s3("Priya", 20);
    Student s4("Rohan", 21, 89.5);

    s1.display();
    s2.display();
    s3.display();
    s4.display();

    return 0;
}
