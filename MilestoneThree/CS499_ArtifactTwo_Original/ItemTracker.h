#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// Class for tracking and item frequency
class ItemTracker {
public:
    ItemTracker(); // Constructor

    int GetItemFrequency(const string& item); // Get item frequency

    void ReadFile(string filename);// Read file

    void PrintItemFrequency();// Print item frequency

    void PrintHistogram();// Print histogram

    void SaveFile(const string& filename);// Save file to frequency.dat


private: // Private data members
    map<string, int> itemFrequency; // Stores item frequency
    ifstream inputFile;// Input file stream
    ofstream outputFile;// Output file stream
};
#endif