@file hello_cin.cpp
@brief stores a user input into a string variable and prints out the message on the screen
@author Kali Cajala

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}