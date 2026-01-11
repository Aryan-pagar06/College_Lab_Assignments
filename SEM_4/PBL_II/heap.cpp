#include <iostream>
using namespace std;
class mobileuser
{
    string username;
    int number;
    string address;
    public:
    void accept();
    void display();
    void seqsearch(mobileuser arr[], int num, string key);
};

void mobileuser::accept()
{
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter number: ";
    cin >> number;
    cout << "Enter address: ";
    cin >> address;
}

void mobileuser::display()
{
    cout << "Username: " << username << endl;
    cout << "Number: " << number << endl;
    cout << "Address: " << address << endl;
}

void mobileuser::seqsearch(mobileuser arr[], int num, string key)
{
    int found = 0;
    for (int i = 0; i < num; i++)
    {
        if (arr[i].username == key)
        {
            cout << "Record found:" << endl;
            arr[i].display();
            found++;
        }
    }
    if (found == 0)
    {
        cout << "Record not found." << endl;
    }
}

int main()
{
    int num;
    string searchKey;
    mobileuser s1[20], s2;
    cout << "Enter number of mobile users: ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter details for user " << (i + 1) << ":" << endl;
        s1[i].accept();
    }
    for (int i = 0; i < num; i++)
    {
        s1[i].display();
    }
    
    cout << "Enter username to search: ";
    cin >> searchKey;
    s2.seqsearch(s1, num, searchKey);
    return 0;
}