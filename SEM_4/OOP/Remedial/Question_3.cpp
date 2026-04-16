#include <iostream>
using namespace std;

class Florist {
private:
    string flowers;
    string gifts;

public:
    // Function to input data
    void setData(string f, string g) {
        flowers = f;
        gifts = g;
    }

    // Function to display data
    void displayData() {
        cout << "Flowers: " << flowers << ", Gifts: " << gifts << endl;
    }
};

int main() {
    // Creating array of 5 objects
    Florist shop[5];

    // Assigning values
    shop[0].setData("Roses", "Teddy Bear");
    shop[1].setData("Lilies", "Chocolate Box");
    shop[2].setData("Tulips", "Greeting Card");
    shop[3].setData("Orchids", "Perfume");
    shop[4].setData("Sunflowers", "Photo Frame");

    // Displaying data
    cout << "Florist Shop Details:\n";
    for(int i = 0; i < 5; i++) {
        shop[i].displayData();
    }

    return 0;
}