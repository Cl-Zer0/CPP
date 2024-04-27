#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Function to encrypt a character using a substitution cipher
char encryptChar(char c, const map<char, char>& cipherMap) {
    auto it = cipherMap.find(c);
    if (it != cipherMap.end()) {
        return it->second;
    }
    return c;
}

// Function to encrypt a string using a substitution cipher
string encrypt(const string& plaintext, const map<char, char>& cipherMap) {
    string ciphertext = "";
    for (char c : plaintext) {
        ciphertext += encryptChar(c, cipherMap);
    }
    return ciphertext;
}

// Function to write a string to a file
void writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Encryption successful. Output written to " << filename << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

int main() {
    string inputFile, outputFile, plaintext;
    map<char, char> cipherMap;

    // Define the substitution cipher (you can customize this as needed)
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key = "xwvutsrqponmlkjihgfedcba";
    for (size_t i = 0; i < alphabet.length(); ++i) {
        cipherMap[alphabet[i]] = key[i];
        cipherMap[toupper(alphabet[i])] = toupper(key[i]);
    }

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    // Reading plaintext from file
    ifstream inFile(inputFile);
    if (inFile.is_open()) {
        plaintext.assign((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
        inFile.close();
    } else {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Encrypting plaintext
    string ciphertext = encrypt(plaintext, cipherMap);

    // Writing encrypted text to file
    writeToFile(outputFile, ciphertext);

    return 0;
}
