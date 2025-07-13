#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to write data to a file
void writeFile(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        string data;
        cout << "Enter data to write (press Enter twice to finish):\n";
        cin.ignore(); // Clear input buffer
        while (getline(cin, data) && !data.empty()) {
            outFile << data << endl;
        }
        outFile.close();
        cout << "Data written to " << filename << " successfully.\n";
    } else {
        cout << "Unable to open file for writing.\n";
    }
}

// Function to append data to a file
void appendFile(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        string data;
        cout << "Enter data to append (press Enter twice to finish):\n";
        cin.ignore(); // Clear input buffer
        while (getline(cin, data) && !data.empty()) {
            outFile << data << endl;
        }
        outFile.close();
        cout << "Data appended to " << filename << " successfully.\n";
    } else {
        cout << "Unable to open file for appending.\n";
    }
}

// Function to read data from a file
void readFile(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "\nContents of " << filename << ":\n";
        cout << "------------------------\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
        cout << "------------------------\n";
    } else {
        cout << "Unable to open file for reading.\n";
    }
}

int main() {
    string filename = "data.txt";
    int choice;

    do {
        cout << "\nFile Operations Menu:\n";
        cout << "1. Write to file\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                appendFile(filename);
                break;
            case 3:
                readFile(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
                default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}