// knapsack.h
#ifndef KNAPSACK_H
#define KNAPSACK_H //header guards

#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Item {
    int id;
    string name;
    int weight;
    int profit;
};

// Function prototypes
void knapsackOptimize(const vector<Item>& items, int capacity, 
                      int& maxProfit, vector<int>& selectedIndices);
void saveToFile(const vector<Item>& items, const string& filename);
void loadFromFile(vector<Item>& items, const string& filename);

#endif