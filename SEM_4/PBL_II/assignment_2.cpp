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
    void quicksort(mobileuser arr[], int low, int high);
    void mergesort(mobileuser arr[], int low, int high);
    void merge(mobileuser arr[], int low, int mid, int end);
    int partition(mobileuser arr[], int low, int high);
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

int mobileuser :: partition(mobileuser arr[], int low, int high)
{
    string pivot=arr[high].username;
    int i=low-1;
    for(int j=low; j<high; j++)
    {
        if(arr[j].username<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void mobileuser :: quicksort(mobileuser arr[], int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int j=partition(arr, low, high);
    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
}

void mobileuser :: mergesort(mobileuser arr[], int low, int high)
{ 
     if(low>=high)
     {
        return;
     }
     int mid=low+(high-low)/2;
     mergesort(arr, low, high);
     mergesort(arr, mid+1, high);
     merge(arr, low, mid, high);
}

void mobileuser :: merge(mobileuser arr[], int low, int mid, int high)
{
  vector<mobileuser>temp(high-low+1);
  int left=low, right = mid+1, index=0;
  while(left<=mid&&right<=high)
  {
    if(arr[left].username<=arr[right].username)
    {
        temp[index]=arr[left];
        index++, left++;
    }
    else{
        temp[index]=arr[right];
        index++, right++;
    }
  }
  while (left<=mid) 
  {
    temp[index]=arr[left];
    index++, left++;
  }
  while(right<=high)
  {
    temp[index]=arr[right];
    index++, right++;
  }
  index=0;
  while(low<=high)
  {
    arr[low]=temp[index];
    low++, index++;
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
    int choice;
    do
    {
    
    cout<<"1) Display all users\n2) Quick sort \n3) Merge sort\n4) Exit\n";
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
        s2.quicksort(s1, 0, num-1);
        cout<<"Usernames sorted!\n";
        break;

        case 3:
        s2.mergesort(s1, 0, num-1);
        cout<<"Usernames sorted!\n";
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