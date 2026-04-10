// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "knapsack.h"

using namespace std;

// Function to display main menu
void displayMenu() {
    cout << "\n═══════════════════════════════════════════\n";
    cout << "   WAREHOUSE OPTIMIZATION SYSTEM\n";
    cout << "═══════════════════════════════════════════\n";
    cout << "  1. Add New Item\n";
    cout << "  2. View All Items\n";
    cout << "  3. Optimize Truck Loading (0/1 Knapsack)\n";
    cout << "  4. Delete Item\n";
    cout << "  5. Compare Algorithms (DP vs Greedy)\n";
    cout << "  6. Save & Exit\n";
    cout << "═══════════════════════════════════════════\n";
    cout << "  Enter your choice: ";
}

// Function to display item in table format
void displayItemTable(const vector<Item>& items) {
    cout << "\n─────────────────────────────────────────────────\n";
    cout << left << setw(5) << "ID" 
         << setw(20) << "Item Name" 
         << setw(10) << "Weight(kg)" 
         << setw(12) << "Profit($)" << endl;
    cout << "─────────────────────────────────────────────────\n";
    
    for (const auto& item : items) {
        cout << left << setw(5) << item.id
             << setw(20) << item.name
             << setw(10) << item.weight
             << setw(12) << item.profit << endl;
    }
    cout << "─────────────────────────────────────────────────\n";
}

// Function to compare DP and Greedy algorithms
void compareAlgorithms(const vector<Item>& items, int capacity) {
    if (items.empty()) {
        cout << "\n⚠ No items available for comparison!\n";
        return;
    }
    
    cout << "\n═══════════════════════════════════════════\n";
    cout << "         ALGORITHM COMPARISON\n";
    cout << "═══════════════════════════════════════════\n";
    
    // Get DP solution
    int dpProfit;
    vector<int> dpIndices;
    knapsackOptimize(items, capacity, dpProfit, dpIndices);
    
    // Greedy solution (by profit/weight ratio)
    vector<pair<double, int>> ratios;
    for (int i = 0; i < items.size(); i++) {
        ratios.push_back({(double)items[i].profit / items[i].weight, i});
    }
    sort(ratios.rbegin(), ratios.rend());
    
    int greedyProfit = 0;
    int greedyWeight = 0;
    vector<int> greedyItems;
    
    for (auto& ratio : ratios) {
        int idx = ratio.second;
        if (greedyWeight + items[idx].weight <= capacity) {
            greedyItems.push_back(idx);
            greedyWeight += items[idx].weight;
            greedyProfit += items[idx].profit;
        }
    }
    
    // Display comparison
    cout << "\n📊 Dynamic Programming (Optimal):\n";
    cout << "   Maximum Profit: $" << dpProfit << "\n";
    cout << "   Items Selected: " << dpIndices.size() << "\n\n";
    
    cout << "📊 Greedy Algorithm (Heuristic):\n";
    cout << "   Maximum Profit: $" << greedyProfit << "\n";
    cout << "   Items Selected: " << greedyItems.size() << "\n";
    cout << "   Total Weight: " << greedyWeight << " kg\n\n";
    
    cout << "📈 Comparison Result:\n";
    if (dpProfit > greedyProfit) {
        cout << "   ✅ DP is better by $" << (dpProfit - greedyProfit) << "\n";
        cout << "   📌 Greedy was " << ((double)greedyProfit/dpProfit)*100 
             << "% optimal\n";
    } else if (dpProfit == greedyProfit) {
        cout << "   ✅ Both algorithms found the same solution!\n";
    } else {
        cout << "   ⚠ Greedy found better solution (unusual for 0/1 knapsack)\n";
    }
    cout << "═══════════════════════════════════════════\n";
}

int main() {
    vector<Item> items;
    int choice;
    
    // Load existing data
    loadFromFile(items, "items.txt");
    
    do {
        displayMenu();
        cin >> choice;
        
        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n✗ Invalid input! Please enter a number between 1-6.\n";
            continue;
        }
        
        switch(choice) {
            case 1: {
                // Add new item
                Item newItem;
                cout << "\n--- Add New Item ---\n";
                cout << "Item ID: ";
                cin >> newItem.id;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✗ Invalid ID!\n";
                    break;
                }
                
                cin.ignore();
                cout << "Item Name: ";
                getline(cin, newItem.name);
                cout << "Weight (kg): ";
                cin >> newItem.weight;
                
                if (cin.fail() || newItem.weight <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✗ Invalid weight!\n";
                    break;
                }
                
                cout << "Profit ($): ";
                cin >> newItem.profit;
                
                if (cin.fail() || newItem.profit <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✗ Invalid profit!\n";
                    break;
                }
                
                items.push_back(newItem);
                cout << "\n✓ Item added successfully!\n";
                break;
            }
            
            case 2: {
                // View all items
                if (items.empty()) {
                    cout << "\n⚠ No items in warehouse!\n";
                } else {
                    displayItemTable(items);
                }
                break;
            }
            
            case 3: {
                // Optimize truck loading
                if (items.empty()) {
                    cout << "\n⚠ No items available for optimization!\n";
                    break;
                }
                
                displayItemTable(items);
                
                int capacity;
                cout << "\nEnter truck weight capacity (kg): ";
                cin >> capacity;
                
                if (cin.fail() || capacity <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✗ Invalid capacity!\n";
                    break;
                }
                
                // Solve knapsack
                int maxProfit;
                vector<int> selectedIndices;
                knapsackOptimize(items, capacity, maxProfit, selectedIndices);
                
                // Display results
                cout << "\n═══════════════════════════════════════════\n";
                cout << "         OPTIMAL LOADING PLAN\n";
                cout << "═══════════════════════════════════════════\n";
                
                if (selectedIndices.empty()) {
                    cout << "No items can be loaded!\n";
                } else {
                    cout << left << setw(20) << "Item Name" 
                         << setw(12) << "Weight(kg)" 
                         << setw(12) << "Profit($)" << endl;
                    cout << "─────────────────────────────────\n";
                    
                    int totalWeight = 0;
                    for (int idx : selectedIndices) {
                        cout << left << setw(20) << items[idx].name
                             << setw(12) << items[idx].weight
                             << setw(12) << items[idx].profit << endl;
                        totalWeight += items[idx].weight;
                    }
                    
                    cout << "─────────────────────────────────\n";
                    cout << "Total Weight: " << totalWeight << " kg\n";
                    cout << "Total Profit: $" << maxProfit << endl;
                    cout << "Capacity Used: " << (totalWeight * 100.0 / capacity) << "%\n";
                }
                cout << "═══════════════════════════════════════════\n";
                break;
            }
            
            case 4: {
                // Delete item
                if (items.empty()) {
                    cout << "\n⚠ No items to delete!\n";
                    break;
                }
                
                displayItemTable(items);
                int delId;
                cout << "\nEnter Item ID to delete: ";
                cin >> delId;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✗ Invalid ID!\n";
                    break;
                }
                
                auto it = remove_if(items.begin(), items.end(), 
                    [delId](const Item& item) { return item.id == delId; });
                
                if (it != items.end()) {
                    items.erase(it, items.end());
                    cout << "\n✓ Item deleted successfully!\n";
                } else {
                    cout << "\n✗ Item not found!\n";
                }
                break;
            }
            
            case 5: {
                // Compare algorithms
                if (items.empty()) {
                    cout << "\n⚠ No items available for comparison!\n";
                    break;
                }
                
                displayItemTable(items);
                int capacity;
                cout << "\nEnter truck weight capacity (kg): ";
                cin >> capacity;
                
                if (cin.fail() || capacity <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✗ Invalid capacity!\n";
                    break;
                }
                
                compareAlgorithms(items, capacity);
                break;
            }
            
            case 6: {
                // Save and exit
                saveToFile(items, "items.txt");
                cout << "\n✓ Data saved. Goodbye!\n";
                break;
            }
            
            default:
                cout << "\n✗ Invalid choice! Please enter a number between 1-6.\n";
        }
        
    } while(choice != 6);
    
    return 0;
}