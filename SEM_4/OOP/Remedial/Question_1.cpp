#include <iostream>
using namespace std;

// Base Class
class Device {
protected:
    string name;
    int pin;
    float voltage;

public:
    // Constructor
    Device(string n, int p, float v) {
        name = n;
        pin = p;
        voltage = v;
    }

    // Pure virtual functions
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
};

// Child Class: Mobile
class Mobile : public Device {
public:
    Mobile() : Device("Mobile", 4, 5.0) {}

    void powerOn() {
        cout << name << " is Powered ON (Pin: " << pin 
             << ", Voltage: " << voltage << "V)" << endl;
    }

    void powerOff() {
        cout << name << " is Powered OFF" << endl;
    }
};

// Child Class: Laptop
class Laptop : public Device {
public:
    Laptop() : Device("Laptop", 3, 19.5) {}

    void powerOn() {
        cout << name << " is Powered ON (Pin: " << pin 
             << ", Voltage: " << voltage << "V)" << endl;
    }

    void powerOff() {
        cout << name << " is Powered OFF" << endl;
    }
};

// Child Class: Tablet
class Tablet : public Device {
public:
    Tablet() : Device("Tablet", 2, 10.0) {}

    void powerOn() {
        cout << name << " is Powered ON (Pin: " << pin 
             << ", Voltage: " << voltage << "V)" << endl;
    }

    void powerOff() {
        cout << name << " is Powered OFF" << endl;
    }
};

// Main Function
int main() {
    Mobile m;
    Laptop l;
    Tablet t;

    cout << "Device Manager Application\n\n";

    m.powerOn();
    m.powerOff();

    cout << endl;

    l.powerOn();
    l.powerOff();

    cout << endl;

    t.powerOn();
    t.powerOff();

    return 0;
}