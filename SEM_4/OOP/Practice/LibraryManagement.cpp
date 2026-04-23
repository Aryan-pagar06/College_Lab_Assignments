#include <iostream>
#include <vector>

using namespace std;

class LibraryItem
{
protected:
    int itemID;
    string title;
    string author;

public:
    LibraryItem(int i, string t, string a)
    {
        itemID = i;
        title = t;
        author = a;
    }

public:
    virtual void displayInfo()
    {
        cout << "Title : " << title << endl;
        cout << "Name of author : " << author << endl;
        cout << "ID : " << itemID << endl;
    }
    int getID()
    {
        return itemID;
    }
};

class Book : public LibraryItem
{
public:
    string genre;
    int pages;
    Book(int i, string t, string a, string g, int pg) : LibraryItem(i, t, a)
    {
        genre = g;
        pages = pg;
    }

public:
    void displayInfo() override
    {
        LibraryItem ::displayInfo();
        cout << "Genre : " << genre << endl;
        cout << "Number of pages : " << pages << endl;
    }
};

class Magzine : public LibraryItem
{
private:
    string issue;
    string publication;

public:
    Magzine(int i, string t, string a, string is, string p) : LibraryItem(i, t, a)
    {
        issue = is;
        publication = p;
    }
    void displayInfo() override
    {
        LibraryItem ::displayInfo();
        cout << "Issued Number : " << issue << endl;
        cout << "Publication date : " << publication << endl;
    }
};

class BorrowRecord
{
    string borrowerName;
    string duedate;
    LibraryItem *libitem;

public:
    BorrowRecord(string bn, string dd, LibraryItem *lb)
    {
        borrowerName = bn;
        duedate = dd;
        libitem = lb;
    }
    void calculateFine()
    {
        int daysOverdue = 10 - 7;      // 10 days borrowed, 7 days free
        double fine = daysOverdue * 5; // ₹5 per extra day
        cout << "Borrower : " << borrowerName << endl;
        cout << "Fine : Rs." << fine << endl;
        libitem->displayInfo(); // show which item was borrowed
    }

    void displayRecord()
    {
        cout << "\n--- Borrow Record ---" << endl;
        cout << "Borrower : " << borrowerName << endl;
        cout << "Due Date : " << duedate << endl;
        libitem->displayInfo();
        calculateFine();
    }
};

class LibraryManager
{
private:
    vector<LibraryItem *> items;
    vector<BorrowRecord> records;

public:
    void addItem(LibraryItem *item)
    {
        items.push_back(item);
    }

    void addRecord(BorrowRecord r)
    {
        records.push_back(r);
    }

    void generateReport()
    {
        cout << "\n===== Library Report =====" << endl;
        for (auto i = records.begin(); i != records.end(); i++)
        {
            i->displayRecord();
        }
    }
};

int main()
{
    Book b1(1, "Maths", "R. D. Sharma", "Education", 500);
    Magzine m1(2, "Times Magzine", "NY times", "10/10/2026", "12/3/2027");

    LibraryManager lm1;
    lm1.addItem(&b1);
    lm1.addItem(&m1);

    BorrowRecord br1("Aryan", "6/10/2006", &b1);
    BorrowRecord br2("rahul", "6/10/2006", &m1);

    lm1.addRecord(br1); // missing!
    lm1.addRecord(br2); // missing!

    lm1.generateReport();
}