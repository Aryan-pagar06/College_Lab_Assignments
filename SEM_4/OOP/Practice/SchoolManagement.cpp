// Base class Person — id, name, contact, constructor, destructor, virtual void display()
// Derived class Student — adds vector<float> marks, overrides display(), has:
// addMarks(float m) — adds one mark
// addMarks(float m1, float m2) — adds two marks at once (this is compile time polymorphism — function overloading)
// getTotal() — returns sum
// getAverage() — returns average

// File handling in main — write student data to students.txt
// main() — create 2 students, add marks, display both, write to file

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Person
{
private:   //encapsulation
    int id;
    string name;
    string contact;

public:
    Person(int i, string n, string con) //constructor
    {
        id = i;
        name = n;
        contact = con;
    }

    ~Person() //destructor
    {
        cout << "Destructor called" << endl;
    }

    virtual void display()
    {
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Contact : " << contact << endl;
    }
};

class Student : public Person //inheritance
{
    vector<float> marks;

public:
    Student(int i, string n, string con) : Person(i, n, con) {}
    void display() override
    {
        Person :: display();
        for (auto i = marks.begin(); i != marks.end(); i++)
        {
            cout << *i << endl;
        }
    }
    void addMarks(float m)
    {
        marks.push_back(m);
    }
    void addMarks(float m1, float m2) //compile time polymorphism
    {
        marks.push_back(m1);
        marks.push_back(m2);
    }
    float getTotal()
    {
        float sum = 0;
        for (auto i = marks.begin(); i != marks.end(); i++)
        {
            sum = sum + *i;
        }
        return sum;
    }
    float getAvg()
    {
        return getTotal() / marks.size();
    }
};

int main()
{
    Student s1(1, "Aryan", "123456");
    Student s2(2, "Om", "23422");
    
    s1.addMarks(100);
    s1.addMarks(95,98);
    s2.addMarks(90);
    s2.addMarks(99,97);

    s1.display();
    cout<<"Total marks : "<<s1.getTotal()<<endl;
    cout<<"Avg marks : "<<s1.getAvg()<<endl;

    s2.display();
    cout<<"Total marks : "<<s2.getTotal()<<endl;
    cout<<"Avg marks : "<<s2.getAvg()<<endl;

    ofstream fout;
    fout.open("Student.txt");
    fout<<"Student 1 - Total : "<<s1.getTotal()<<"Avg : "<<s1.getAvg()<<endl;
    fout<<"Student 2 - Total : "<<s2.getTotal()<<"Avg : "<<s2.getAvg()<<endl;
    fout.close();

    cout<<"Details entered in Student.txt"<<endl;

    ifstream fin;
    fin.open("Student.txt");
    char c = fin.get();
    while(! fin.eof()) {
       cout<<c;
       c = fin.get();
    }

    fin.close();


}
