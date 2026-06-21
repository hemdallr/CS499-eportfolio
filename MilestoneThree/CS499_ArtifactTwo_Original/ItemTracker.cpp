#include "ItemTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

ItemTracker::ItemTracker() { // Constructor
    itemFrequency = map<string, int>(); // Initialize map
}

void ItemTracker::ReadFile(string filename) { // Read .txt file
   ifstream inputFile(filename); // Open .txt file
    if (!inputFile) { // Check if file sucessfully opened
        cout << "Could not open file: " << filename << endl;
        return;
    }
   
    string item; 

    while (inputFile >> item) { // Loop through each item in the file
        itemFrequency[item]++;// Increment item frequency
    }
    inputFile.close();// Close the file
}

int ItemTracker::GetItemFrequency(const string& item) { // Get item frequency
    if (itemFrequency.count(item) > 0) { // Check for item in map
        return itemFrequency.at(item); // Return frequency
    }
    return 0;
}

void ItemTracker::PrintItemFrequency() { // Print item frequency
    if (itemFrequency.empty()) { // Check if empty
        cout << "No items available." << endl;
        return;
    }
    for (pair<string, int> item : itemFrequency) {// Loop through map and print item with frequency
        cout << item.first << " " << item.second << endl;
    }
}

void ItemTracker::PrintHistogram() { // Print histogram
    if (itemFrequency.empty()) { // Check if empty 
        cout << "Item not available." << endl; 
        return;
    }
    for (pair<string, int> item: itemFrequency) { // Loop through map 
        cout << item.first << " ";
        for (int i = 0; i < item.second; i++) {// Print "*" matching the item frequency
            cout << "*";
        }
        cout << endl;
    }
}

void ItemTracker::SaveFile(const string& filename) { // Save file to frequency.dat
    ofstream outputFile(filename);
    if (!outputFile) { // Check if file successfully opened
        cout << "Could not open file: " << filename << endl;
        return;
    }
    for (pair<string, int> item : itemFrequency) {// Loop through map and write to file
        outputFile << item.first << " " << item.second << endl;
    }
    outputFile.close(); // Close the file
}