/*
 Project: Caesar Cipher Encoder/Decoder               
 Developer: Mark Emad Fouad                                  
*/

#include <bits/stdc++.h>
using namespace std;

/* 
Encrypts a message by shifting letters forward in the alphabet
Parameters:
- inputText: the original message to encrypt
- shift: number of positions to shift each character
*/
void Encrypt(string inputText, int shift) {

    // Process each character in the string
    for(char &s: inputText) {

        // Only modify alphabetical characters
        if(isalpha(s)) {

            // Handle uppercase letters (A-Z)
            if(s < 'a') {
                s += shift;           // Apply shift
                if(s > 'Z') s -= 26; // Wrap around if past Z
            } 
            // Handle lowercase letters (a-z)
            else {
                s += shift;           // Apply shift
                if(s > 'z') s -= 26; // Wrap around if past z
            }
        } 
    }

    cout << "The encoded message is " << inputText << "\n";
}

/*
Decrypts a message by shifting letters backward in the alphabet
Parameters:
- inputText: the encrypted message to decrypt
- shift: number of positions to shift each character
*/
void Decrypt(string inputText, int shift) {

    // Process each character in the string
    for(char &s: inputText) {

        // Only modify alphabetical characters
        if(isalpha(s)) {

            // Handle uppercase letters (A-Z)
            if(s < 'a') {
                s -= shift;           // Reverse shift
                if(s < 'A') s += 26; // Wrap around if before A
            } 
            // Handle lowercase letters (a-z)
            else {
                s -= shift;           // Reverse shift
                if(s < 'a') s += 26; // Wrap around if before a
            }
        }
    }

    cout << "The decoded message is " << inputText << "\n";
}

/*
Main program driver
- Gets user input for operation type
- Validates input parameters
- Calls appropriate encryption/decryption function
*/
int main() {
    
    string codeType, inputText;
    int shift;

    // Get operation type from user
    cout << "Type 'encode' to encrypt or 'decode' to decrypt: ";
    cin >> codeType;
    
    // Validate operation type
    if(codeType != "encode" && codeType != "decode") {
        cout << "Invalid input\n";
        return 0;
    }

    // Get message input (NOTE: won't work with spaces)
    cout << "Type the message: ";
    cin >> inputText;

    // Get shift value
    cout << "Enter the number of shifts: ";
    cin >> shift;

    // Execute requested operation
    if(codeType == "encode") Encrypt(inputText, shift);
    else Decrypt(inputText, shift);

    return 0;
}