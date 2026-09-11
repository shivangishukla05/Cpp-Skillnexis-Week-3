#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Shape" << endl;
    }
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void area() override {
        cout << "Circle Area: " << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape {
    float length, breadth;

public:
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    void area() override {
        cout << "Rectangle Area: " << length * breadth << endl;
    }
};

int main() {
    Circle c(5);
    Rectangle r(10, 5);

    c.area();
    r.area();

    return 0;
}
