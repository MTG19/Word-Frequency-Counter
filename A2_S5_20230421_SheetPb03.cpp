// File: A2_S5_20230421_SheetPb03.cpp
// Purpose: This program is a useful tool for text analysis, specifically for counting the frequency of words in a document.
//          It also demonstrates the power of STL containers like map for efficiently managing key-value pairs in C++.
//          By utilizing basic string manipulation functions and STL features, Farah can quickly generate a frequency table that meets the company's document retrieval criteria.
// Author: Menna Talla Gamal Mahmoud
// Section: S5
// ID: 20230421

#include <iostream>     // For standard I/O operations (cout, cin, cerr)
#include <fstream>      // For file operations (ifstream)
#include <map>          // For using STL map container to store word-frequency pairs
#include <cctype>       // For character-handling functions like isalnum and tolower
#include <string>       // For using the string class

using namespace std;

// Function to clean and process a word by removing non-alphanumeric characters and converting to lowercase
string onlyWord(const string &word) {
    string cleanWord;   // Initialize an empty string to store the cleaned word
    for (char ch : word) {   // Loop through each character in the input word
        if (isalnum(ch) || ch == '-') { // Keep only alphanumeric characters and hyphens
            cleanWord += tolower(ch);    // Convert character to lowercase and add to cleanWord
        }
    }
    return cleanWord;    // Return the cleaned word
}
//----------------------------------------------------------------

int main() {
    cout << "__Welcome to the Word Frequency Counter!__\n__________________________________________\n\n";

    string filename;      // Variable to store the file name or path
    ifstream file;        // Input file stream for reading the file
    int choice;          // Variable to store the user's choice to check another file or exit

    do {
        // Keep asking for a valid filename until the file is successfully opened
        while (true) {
            cout << "Please enter the full path of the file without (' '): ";
            cin >> filename;

            file.open(filename); // Try to open the file with the given filename
            if (file.is_open()) {   // Check if the file was opened successfully
                break;   // Exit the loop if the file opens successfully
            } else {
                cerr << "Could not open the file. Please try again.\n";
                file.clear();    // Clear the error flag on the file stream to allow another attempt
            }
        }

        map<string, int> frequency;    // Declare a map to store words and their frequency counts
        string word;    // Variable to store each word read from the file

        // Read each word from the file one by one
        while (file >> word) {
            word = onlyWord(word);   // Clean and process each word using onlyWord function
            if (!word.empty()) {    // Check if the processed word is not empty
                frequency[word]++;    // Increment the count of the word in the frequency map
            }
        }

        file.close();    // Close the file after reading all words

        cout << "\nFrequency Table for all words:\n_______________________________\n";
        for (const auto &x : frequency) {   // Loop through each entry in the frequency map
            cout << x.first << " : " << x.second << endl;  // Output the word and its frequency count
        }
        cout << "_______________________________________________________________________\n";

        // Ask the user if they want to check another file or exit
        while (true) {
            cout << "\nDo you want to:\n 1.check another file? \n 2.Exit the program? \nChoose 1 or 2 :\n";
            cin >> choice;

            if (choice == 1 || choice == 2) {
                break;   // Valid choice, exit the inner loop
            } else {
                cout << "Invalid choice. Please enter 1 or 2.\n";
                cin.clear();    // Clear the error flag on the input stream to allow another attempt
                cin.ignore();
            }
        }
    } while (choice == 1);   // Continue if the user wants to check another file

    cout << "______________________________________\nThanks for using the program. Goodbye!\n______________________________________";

    return 0;   // End the program
}
