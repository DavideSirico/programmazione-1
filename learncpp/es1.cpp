#include <iostream>
using namespace std;

// Write a program that asks the user to enter a number, and then enter a second number. The program should tell the user what the result of adding and subtracting the two numbers is.

int main() {
    int x = 0,y = 0;
    cout << "Enter an integer: ";
    cin >> x;
    cout << "Enter another integer: ";
    cin >> y;
    cout << x << " + " << y << " is " << x+y << endl;
    cout << x << " - " << y << " is " << x-y << endl;
    return 0;

}