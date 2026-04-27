#include <iostream>
#include <fstream>

using namespace std;

class Person
{
private:
    int id;
    string name;

public:
    Person(int i, string n)
    {
        id = i;
        name = n;
    }
    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name : " << name << endl;
    }
};

class Employee : public Person
{
private :
    double basic_sal;
    double allowance;

public:
    Employee(int i, string n, double bs, double a) : Person(i, n)
    {
        if(bs < 0) throw "Invalid salary";
        basic_sal = bs;
        allowance = a;
    }
    void display () override {
        Person :: display();
        cout<<"Basic pay = "<<basic_sal<<endl;
        cout<<"Allowance = "<<allowance<<endl;
    }
    double getSal() {
        return basic_sal + allowance;
    }
    void addBonus (double amount) {
       basic_sal = basic_sal + amount;
    }
    void addBonus (double amount, double extra) {
        basic_sal = basic_sal + amount + extra;
    }
};

int main ()
{
    Employee e1(1, "Aryan", 100000, 70000);
    Employee e2(2, "Om", 50000, 30000);

    Person *p;
    p = &e1;
    p -> display();
    p = &e2;
    p -> display();


    e1.addBonus(30000);
    e2.addBonus(1000, 200);

    cout<<"Total salary of e1 : "<<e1.getSal()<<endl;
    cout<<"Total salary of e2 : "<<e2.getSal()<<endl;

    ofstream fout;
    fout.open("Employee.txt");
    fout<<"EMPLOYEE DETAILS : "<<endl;
    fout<<"E1 : "<< "Total salary = "<<e1.getSal()<<endl;
    fout<<"E2 : "<< "Total salary = "<<e2.getSal()<<endl;

    fout.close();

    ifstream fin;
    fin.open("Employee.txt");
    char c = fin.get();
    while(! fin.eof()) {
        cout<<c;
        c = fin.get();
    }

    fin.close();

}
