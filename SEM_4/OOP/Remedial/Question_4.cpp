#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    // Pure virtual functions
    virtual void area() = 0;
    virtual void volume() = 0;
};

// Derived Class: Circle
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void area() {
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }

    void volume() {
        cout << "Circle has no volume" << endl;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    float length, breadth;

public:
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    void area() {
        cout << "Area of Rectangle = " << length * breadth << endl;
    }

    void volume() {
        cout << "Rectangle has no volume" << endl;
    }
};

// Derived Class: Square
class Square : public Shape {
private:
    float side;

public:
    Square(float s) {
        side = s;
    }

    void area() {
        cout << "Area of Square = " << side * side << endl;
    }

    void volume() {
        cout << "Square has no volume" << endl;
    }
};

// Main Function
int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Square s(3);

    cout << "Shape Calculations:\n\n";

    c.area();
    c.volume();

    cout << endl;

    r.area();
    r.volume();

    cout << endl;

    s.area();
    s.volume();

    return 0;
}