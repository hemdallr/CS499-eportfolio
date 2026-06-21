/*
    CS210 Project Three
    Southern New Hampshire University
    Author: Jonathan Hodge
    Date: 02/23/2025

    This project reads a list of items from a file, and tracks the frequency of each item.
    A menu is created for the user to choose from.
    1. Get Item frequency
    2. Print list of items and frequency
    3. Print histogram of items
    4. Exit Program
*/

#include "ItemTracker.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
    ItemTracker itemTracker; // Create object for item tracker
    string filename = "CS210_Project_Three_Input_File.txt"; // name of file for reading 
    itemTracker.ReadFile(filename);// Read items from file

    itemTracker.SaveFile("frequency.dat");// Save file to frequency.dat in beginning of program

    int choice;// Stores users choice
    string item; // Stores user input for item name
    
    do {// Loops until user chooses to exit
        // Displays menu
        cout << "========================================" << endl;
        cout << "Please choose an option from the menu:" << endl;
        cout << "1. Get Item frequency" << endl;
        cout << "2. Print list of items and frequency" << endl;
        cout << "3. Print histogram of items" << endl;
        cout << "4. Exit Program" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: " << endl;

        // Get user input and check to make sure input is valid since it would cause an infinite loop if wrong input was entered
        if (!(cin >> choice)) {// Check for invalid input
            cout << "Invalid input. Please choose 1-4." << endl;
            cin.clear();// Clear input buffer
            cin.ignore(500, '\n');// Ignore invalid input
            continue;// Continue
        }

        // Switch statement to process users choice
        switch (choice) {
            case 1:// Get item frequency
                cout << "Enter item name: ";
                cin >> item;
                cout << "Frequency of " << item << " is " << itemTracker.GetItemFrequency(item) << endl;
                break;
            case 2: // Print a list of item frequencies
                itemTracker.PrintItemFrequency();
                break;
            case 3:// Print a list of item frequencies with "*"
                itemTracker.PrintHistogram();
                break;
            case 4:// Exit program
               cout << "Exiting program!" << endl;
                break;
            
            default:// Invalid choice
                cout << "Invalid choice. Please try again." << endl;

        }
    } while (choice != 4);// Loops until user chooses option 4

 return 0;
 }