#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to write (create/overwrite) a file
void writeToFile(const string &filename) {
    ofstream outFile(filename); // opens in write mode by default (truncate/overwrite)

    if (!outFile) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }

    cout << "Enter text to write to the file (end with a single line containing only #):\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") {
            break;
        }
        outFile << line << '\n';
    }

    outFile.close();
    cout << "Data written to " << filename << " successfully.\n";
}

// Function to read a file
void readFromFile(const string &filename) {
    ifstream inFile(filename); // open in read mode

    if (!inFile) {
        cout << "Error: Could not open file for reading. File may not exist.\n";
        return;
    }

    cout << "\n--- Contents of " << filename << " ---\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << '\n';
    }
    cout << "--- End of file ---\n";

    inFile.close();
}

// Function to append to a file
void appendToFile(const string &filename) {
    ofstream outFile(filename, ios::app); // open in append mode

    if (!outFile) {
        cout << "Error: Could not open file for appending.\n";
        return;
    }

    cout << "Enter text to append to the file (end with a single line containing only #):\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") {
            break;
        }
        outFile << line << '\n';
    }

    outFile.close();
    cout << "Data appended to " << filename << " successfully.\n";
}

int main() {
    string filename;
    int choice;

    cout << "===== FILE MANAGEMENT TOOL =====\n";
    cout << "Enter the file name (e.g., data.txt): ";
    getline(cin, filename);

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Write to file (create/overwrite)\n";
        cout << "2. Read from file\n";
        cout << "3. Append to file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear leftover newline in input buffer before using getline again
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                readFromFile(filename);
                break;
            case 3:
                appendToFile(filename);
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
