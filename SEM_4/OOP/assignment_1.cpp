#include <iostream>
using namespace std;

class shapes
{
public:
    void areasq(float a)
    {
        cout << "Area of square = " << a * a << endl;
    }

    void arearec(float l, float w)
    {
        cout << "Area of rectangle = " << l * w << endl;
    }

    void areatri(float b, float h)
    {
        cout << "Area of triangle = " << 0.5 * b * h << endl;
    }
};

int main()
{
    shapes s;

    float a, l, w, b, h;

    cout << "Enter side of square: ";
    cin >> a;
    s.areasq(a);

    cout << "\nEnter length and width of rectangle: ";
    cin >> l >> w;
    s.arearec(l, w);

    cout << "\nEnter base and height of triangle: ";
    cin >> b >> h;
    s.areatri(b, h);

    return 0;
}