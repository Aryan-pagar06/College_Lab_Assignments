#include <iostream>
using namespace std;

class shape {
    public :
    virtual void draw() {
        cout<<"I am base shape";
    }
};

class rectangle : public shape {
    public :
     void draw() {
        cout<<"I am rectangle";
    }
};

class circle : public shape {
    public :
     void draw() {
        cout<<"I am circle";
    }
};

int main () {
    shape s1;
    s1.draw();
    rectangle r1;
    r1.draw();
    circle c1;
    c1.draw();
    shape *ptr;
    ptr=&r1;
    ptr->draw();
}

