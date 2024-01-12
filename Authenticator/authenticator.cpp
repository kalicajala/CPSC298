// @file authenticator.cpp
// @brief checks 3 letter code entered by a user to see if matches the actual code
// @author Kali Cajala

#include <iostream>

int main() {
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';

    char messageCodeCharacter1;
    char messageCodeCharacter2;
    char messageCodeCharacter3;

    std::cout << "Enter the first character of the message code: " << std::endl;
    std::cin >> messageCodeCharacter1;
    std::cout << "Enter the second character of the message code: " << std::endl;
    std::cin >> messageCodeCharacter2;
    std::cout << "Enter the third character of the message code: " << std::endl;
    std::cin >> messageCodeCharacter3;

    std::string authenticatorCode;
    authenticatorCode += k_cAuthenticatorCodeCharacter1;
    authenticatorCode += k_cAuthenticatorCodeCharacter2;
    authenticatorCode += k_cAuthenticatorCodeCharacter3;

    std::string messageCode;
    messageCode += messageCodeCharacter1;
    messageCode += messageCodeCharacter2;
    messageCode += messageCodeCharacter3;

    std::cout << std::endl;
    std::cout << "Authenticator Code: " << authenticatorCode << std::endl;
    std::cout << "Message Code: " << messageCode << std::endl;
    std::cout << std::endl;

    if (messageCodeCharacter1 == k_cAuthenticatorCodeCharacter1 &&
        messageCodeCharacter2 == k_cAuthenticatorCodeCharacter2 &&
        messageCodeCharacter3 == k_cAuthenticatorCodeCharacter3) {
        std::cout << "Message is authentic." << std::endl;
    }
    else {
        std::cout << "Message is invalid." << std::endl;
    }

    if (messageCode == authenticatorCode) {
        std::cout << "Concurrence: message is authentic." << std::endl;
    }
    else {
        std::cout << "Concurrence: message is invalid." << std::endl;
    }

    
    std::cout << std::endl;
    std::cout << "Characterization of Message Code" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    int messageCodeChar1Val = static_cast<int>(messageCodeCharacter1);
    int messageCodeChar2Val = static_cast<int>(messageCodeCharacter2);
    int messageCodeChar3Val = static_cast<int>(messageCodeCharacter3);
    int totalAsciiVal = messageCodeChar1Val + messageCodeChar2Val + messageCodeChar3Val;

    std::cout << "ASCII Values of Message Code Characters: " << messageCodeChar1Val << ", " << messageCodeChar2Val << ", " << messageCodeChar3Val << std::endl;
    std::cout << "Sum of ASCII values for Message Code Characters: " << totalAsciiVal << std::endl;

    int checksum = 0;
    checksum = (int(messageCodeCharacter1) + int(messageCodeCharacter2) + int(messageCodeCharacter3)) % 7;
    const int k_iValidCodeChecksum = 5;

    if (checksum == k_iValidCodeChecksum) {
        std::cout << "Message Code Checksum is valid: " << checksum << std::endl;
    }
    else {
        std::cout << "Message Code Checksum is invalid: " << checksum << "; expected: " << k_iValidCodeChecksum << std::endl;
    }

    if (messageCodeCharacter1 != k_cAuthenticatorCodeCharacter1) {
        std::cout << "First characters do not match: Message: " << messageCodeCharacter1 << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << std::endl;
    }
    if (messageCodeCharacter2 != k_cAuthenticatorCodeCharacter2) {
        std::cout << "Second characters do not match: Message: " << messageCodeCharacter2 << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << std::endl;
    }
    if (messageCodeCharacter3 != k_cAuthenticatorCodeCharacter3) {
        std::cout << "Third characters do not match: Message: " << messageCodeCharacter3 << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << std::endl;
    }

    if (messageCode != authenticatorCode) {
        if (messageCode < authenticatorCode) {
            std::cout << "Message Code (" << messageCode << ") is lexigraphically less than Authenticator code (" << authenticatorCode << ")" << std::endl;
        }
        else if (messageCode > authenticatorCode) {
            std::cout << "Message Code (" << messageCode << ") is lexigraphically greather than Authenticator code (" << authenticatorCode << ")" << std::endl;
        }
    }
}