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
    void binarysearch(mobileuser arr[], int num, string key);
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

void mobileuser::binarysearch(mobileuser arr[], int num, string key)
{
  int low=0;
  int high=num-1;
  while(low<=high)
  {
    int mid = (low + high)/2;
    if(key==arr[mid].username)
    {
       cout<<"Record found!\n";
       arr[mid].display();
       return;
    }
    else if(key <arr[mid].username)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
  }
  cout<<"Record not found!\n";
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
    int choice;
    do
    {
    
    cout<<"1) Display all users\n2) Linear search\n3) Binary search\n4) Exit";
    cout<<"Enter your choice : ";
    cin>>choice;
    switch (choice)
    {
        case 1: 
        for (int i = 0; i < num; i++)
        {
        cout<<"Registered user " << (i+1)<< ":" << endl;
        s1[i].display();
        }
        break;

        case 2:
            cout << "Enter username to search: ";
            cin >> searchKey;
            s2.seqsearch(s1, num, searchKey);
            break;
        
        case 3:
            cout << "Enter username to search: ";
            cin >> searchKey;
            s2.binarysearch(s1, num, searchKey);
            break;

        case 4:
        cout<<"Thank you!\n";
        break;

        default:
        cout<<"Invalid choice\n";

    } 
    }while(choice != 4);

    return 0;
}