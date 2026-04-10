// knapsack.cpp
#include "knapsack.h"
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

// 0/1 Knapsack using Dynamic Programming
void knapsackOptimize(const vector<Item>& items, int capacity, 
                      int& maxProfit, vector<int>& selectedIndices) {
    int n = items.size();
    
    // Create DP table (n+1) x (capacity+1)
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i-1].weight <= w) {
                // Include or exclude current item
                int include = items[i-1].profit + dp[i-1][w - items[i-1].weight]; // dp table condition
                int exclude = dp[i-1][w];
                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // Max profit is at dp[n][capacity]
    maxProfit = dp[n][capacity];
    
    // Backtrack to find which items are selected
    selectedIndices.clear();
    int w = capacity;
    int remainingProfit = maxProfit;
    
    for (int i = n; i > 0 && remainingProfit > 0; i--) {
        if (remainingProfit != dp[i-1][w]) {
            selectedIndices.push_back(i-1);  // Add index
            remainingProfit -= items[i-1].profit;
            w -= items[i-1].weight;
        }
    }
    
    // Reverse to maintain original order
    reverse(selectedIndices.begin(), selectedIndices.end());
}

// Save items to file
void saveToFile(const vector<Item>& items, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot save to file!\n";
        return;
    }
    
    for (const auto& item : items) {
        file << item.id << ","
             << item.name << ","
             << item.weight << ","
             << item.profit << "\n";
    }
    file.close();
}

// Load items from file
void loadFromFile(vector<Item>& items, const string& filename) {
    items.clear();
    ifstream file(filename);
    
    if (!file.is_open()) {
        // File doesn't exist, create empty one
        ofstream newFile(filename);
        newFile.close();
        return;
    }
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string token;
        Item item;
        
        getline(ss, token, ',');
        item.id = stoi(token);
        
        getline(ss, item.name, ',');
        
        getline(ss, token, ',');
        item.weight = stoi(token);
        
        getline(ss, token, ',');
        item.profit = stoi(token);
        
        items.push_back(item);
    }
    file.close();
}