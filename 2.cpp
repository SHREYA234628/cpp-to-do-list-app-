#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to encrypt text using Caesar Cipher
string encryptText(const string &text, int key) {
    string encrypted = text;
    for (char &c : encrypted) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + key) % 26 + base;
        }
    }
    return encrypted;
}

// Function to decrypt text using Caesar Cipher
string decryptText(const string &text, int key) {
    string decrypted = text;
    for (char &c : decrypted) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - key + 26) % 26 + base;
        }
    }
    return decrypted;
}

int main() {
    int choice, key;
    string inputFile, outputFile, line, result;

    cout << "--- FILE ENCRYPTION/DECRYPTION ---\n";
    cout << "1. Encrypt File\n";
    cout << "2. Decrypt File\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter shift key (e.g., 3): ";
    cin >> key;

    cout << "Enter input file name (with extension): ";
    cin >> inputFile;

    ifstream inFile(inputFile);
    if (!inFile) {
        cout << " Error: Cannot open input file.\n";
        return 1;
    }

    if (choice == 1) {
        outputFile = "encrypted.txt";
    } else if (choice == 2) {
        outputFile = "decrypted.txt";
    } else {
        cout << "Invalid choice!\n";
        return 1;
    }

    ofstream outFile(outputFile);
    if (!outFile) {
        cout << " Error: Cannot create output file.\n";
        return 1;
    }

    while (getline(inFile, line)) {
        if (choice == 1) {
            result = encryptText(line, key);
        } else {
            result = decryptText(line, key);
        }
        outFile << result << "\n";
    }

    cout << " Process completed! Output saved in " << outputFile << endl;

    inFile.close();
    outFile.close();
    return 0;
}
