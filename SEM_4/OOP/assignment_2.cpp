//bank operations using class and objects

#include <iostream>
using namespace std;

class bank
{
   double bal;
   string name;
   string address;
   double amount;
   int account;
   string pan;
   public:
   void open_account();
   void deposit_money();
   void withdraw();
   void checkbalance();
   void kyc();

};

void bank :: open_account()
{
   cout << "Enter Name: ";
   cin >> name;
   cout << "Enter Address: ";
   cin >> address;
   cout << "Enter PAN : ";
   cin >> pan;
   cout<<"Enter money to deposit: ";
   cin>>amount;
   bal = amount;
   cout << "Account opened successfully!" << endl;
   cout<<"Your account number is : ";
   cout<<account;
   cout<<"\n";
}

void bank :: deposit_money()
{
    cout<<"Enter money to deposit : ";
    cin>>amount;
    cout<<"\n";
    bal=bal+amount;
    cout<<"Money deposited";
}

void bank :: checkbalance()
{
   cout<<"Current Balance : ";
   cout<<bal;
}

void bank :: withdraw()
{
   cout<<"Enter the amount to withdraw : ";
   cin>>amount;
   bal=bal-amount;
   cout<<"Money withdrawn";
}

void bank :: kyc()
{
   cout<<"Name : ";
   cout<<name;
   cout<<"\n";
   cout<<"Address : ";
   cout<<address;
   cout<<"\n";
   cout<<"Account Number : ";
   cout<<account;
   cout<<"\n";
   cout<<"PAN : ";
   cout<<pan;
   cout<<"\n";
}


int main ()
{
   char choice;
   bank obj;
   cout<<"Welcome to World Bank!";
   cout<<"\n";
   cout<<"Do you wish to create a bank account (y/n) : ";
   cin>>choice;
   if(choice == 'n')
   {
      cout<<"Thank you!";
      return 0;
   }
   else if (choice == 'y')
   {

      int option;
      obj.open_account();
      cout<<"1) Deposit money\n2)Withdraw money\n3)Check balance\n4)KYC\n5)Exit\n";
      cout<<"\nEnter an option :";
      cin>>option;
      while(option != 5)
      {
         switch (option)
         {
         case 1: 
         obj.deposit_money();
         cout<<"\nEnter an option :";
         cin>>option;
         break;

         case 2:
         obj.withdraw();
         cout<<"\nEnter an option :";
         cin>>option;
         break;

         case 3:
         obj.checkbalance();
         cout<<"\nEnter an option :";
         cin>>option;
         break;

         case 4:
         obj.kyc();
         cout<<"\nEnter an option :";
         cin>>option;
         break;

         case 5:
         cout<<"Thank you";
         
         default:
         cout<<"Enter valid option";
         cout<<"\nEnter an option :";
         cin>>option;
         break;

         }

      }
      
   }
   else 
   {
      cout<<"Enter valid option\n";
      cout<<"Do you wish to create a bank account (y/n) : ";
      cin>>choice;     
   }

}