#include <iostream>
#include <vector>

using namespace std;

class Student 
{
    int rollno;
    string name;
    vector<double> marks;

public:

    // Default constructor
    Student() 
    {
        rollno = 0;
        name = "";
    }

    // Parameterized constructor
    Student(int roll, string n) 
    {
        rollno = roll;
        name = n;
    }

    // Function to add marks
    void addMarks(double m) 
    {
        marks.push_back(m);
    }

    // Display details
    void display() 
    {
        cout << "Name : " << name << endl;
        cout << "Roll no : " << rollno << endl;

        cout << "Marks : ";
        for (vector<double>::iterator i = marks.begin(); i != marks.end(); i++) 
        {
            cout << *i << " ";
        }
        cout << endl;
    }

    // Get maximum marks
    double getMax() 
    {
        double maxi = INT_MIN;
        for (vector<double>::iterator i = marks.begin(); i != marks.end(); i++) 
        {
            if (*i > maxi)
                maxi = *i;
        }
        return maxi;
    }

    // Get minimum marks
    double getMin() 
    {
        double mini = INT_MAX;
        for (vector<double>::iterator i = marks.begin(); i != marks.end(); i++) 
        {
            if (*i < mini)
                mini = *i;
        }
        return mini;
    }

    // Get average marks
    double getAverage() 
    {
        double sum = 0;
        for (vector<double>::iterator i = marks.begin(); i != marks.end(); i++) 
        {
            sum += *i;
        }
        return sum / marks.size();
    }
};

int main()
{
    Student s1(1, "Aryan");

    s1.addMarks(85);
    s1.addMarks(90);
    s1.addMarks(78);

    s1.display();

    cout << "Max Marks: " << s1.getMax() << endl;
    cout << "Min Marks: " << s1.getMin() << endl;
    cout << "Average Marks: " << s1.getAverage() << endl;

    return 0;
}