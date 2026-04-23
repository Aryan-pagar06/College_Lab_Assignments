#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int roll;
    Student(int r, string n) {
        roll = r;
        name = n;
    }
};

int main()
{
    vector <string> names;
    names.push_back("Aryan");
    names.push_back("Rohan");
    names.push_back("Om");
    names.push_back("Rahul");
    names.push_back("Bharati");

    for(auto i = names.begin(); i != names.end(); i++) {
        cout<< *i << endl;
    }

    cout<<"Size = "<<names.size()<<endl;


}