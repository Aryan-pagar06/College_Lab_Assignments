#include <iostream>
using namespace std;

class Circle 
{
public:
    int radius;

    // Parameterized constructor
    Circle(int rad) 
    {
        radius = rad;
        cout << "Parameterized constructor called\n";
    }

    // Default constructor
    Circle() 
    {
        radius = 10;
        cout << "Default constructor called\n";
    }

    // Function to calculate area
    double getArea() 
    {
        return 3.14 * radius * radius;
    }

    // Function to calculate circumference
    double getCircumference() 
    {
        return 2 * 3.14 * radius;
    }

    // Destructor
    ~Circle() 
    {
        cout << "Destructor called\n";
    }
};

int main()
{
    Circle c1;        // Default constructor
    Circle c2(100);   // Parameterized constructor

    cout << "Area of c1 is: " << c1.getArea() << endl;
    cout << "Area of c2 is: " << c2.getArea() << endl;

    cout << "Circumference of c1 is: " << c1.getCircumference() << endl;
    cout << "Circumference of c2 is: " << c2.getCircumference() << endl;

    return 0;
}