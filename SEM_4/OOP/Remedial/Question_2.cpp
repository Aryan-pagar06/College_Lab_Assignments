#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    void getPersonData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPersonData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class 1
class Teacher : virtual public Person {
protected:
    string subject;

public:
    void getTeacherData() {
        cout << "Enter Subject: ";
        cin >> subject;
    }

    void displayTeacherData() {
        cout << "Subject: " << subject << endl;
    }
};

// Derived Class 2
class Admin : virtual public Person {
protected:
    string department;

public:
    void getAdminData() {
        cout << "Enter Department: ";
        cin >> department;
    }

    void displayAdminData() {
        cout << "Department: " << department << endl;
    }
};

// Hybrid Inheritance Class
class Employee : public Teacher, public Admin {
private:
    int empID;

public:
    void getEmployeeData() {
        getPersonData();
        getTeacherData();
        getAdminData();

        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    void displayEmployeeData() {
        displayPersonData();
        displayTeacherData();
        displayAdminData();
        cout << "Employee ID: " << empID << endl;
    }
};

// Main Function
int main() {
    Employee e;

    cout << "Enter Employee Details:\n";
    e.getEmployeeData();

    cout << "\nEmployee Details:\n";
    e.displayEmployeeData();

    return 0;
}