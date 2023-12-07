//yisak worku yxw190038

#include <iostream>
#include <fstream>
#include "Encryption.cpp"
#include "Encryption.h"
#include "Uppercase.cpp"
#include "Uppercase.h"
#include "Copy.h"
#include "Copy.cpp"
using namespace std;


int main() {
    string inputFile;
    cout << "Enter the input file name: ";
    cin >> inputFile;

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Encryption with default key
    Encryption encryptionDefault;
    encryptionDefault.doFilter(inFile, ofstream("EncryptionDefault.txt"));

    // Encryption with key value of 12
    inFile.clear(); // Clear the end-of-file flag
    inFile.seekg(0, ios::beg); // Move the file pointer to the beginning
    Encryption encryption12(12);
    encryption12.doFilter(inFile, ofstream("Encryption12.txt"));

    // Encryption with key value of -4
    inFile.clear();
    inFile.seekg(0, ios::beg);
    Encryption encryptionNeg4(-4);
    encryptionNeg4.doFilter(inFile, ofstream("Encryption-4.txt"));

    // Uppercase transformation
    inFile.clear();
    inFile.seekg(0, ios::beg);
    Uppercase uppercaseFilter;
    uppercaseFilter.doFilter(inFile, ofstream("Uppercase.txt"));

    // Copy without modification
    inFile.clear();
    inFile.seekg(0, ios::beg);
    Copy copyFilter;
    copyFilter.doFilter(inFile, ofstream("Copy.txt"));

    cout << "Filtering completed successfully." << endl;

    return 0;
}
