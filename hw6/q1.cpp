// ================================================== //
// -- File      : q1.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 27/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// struct declaration
struct Time
{
    int  hour;
    int  minute;
    int  second;
};

int main()
{
    Time  t;

    cout << "Enter hour: ";
    cin >> t.hour;

    cout << "Enter minute: ";
    cin >> t.minute;

    cout << "Enter second: ";
    cin >> t.second;

    cout << "Time: " << t.hour << ":" << t.minute << ":" << t.second << endl;

    return 0;
}
