#include <iostream>
using namespace std;

class Student {
    string name;
    int marks;

public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;
    s.getData();
    s.display();

    return 0;
}
