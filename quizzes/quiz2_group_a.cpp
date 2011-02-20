// ================================================== //
// -- File      : quiz2_group_a.cpp         --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 27/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// struct declaration
struct Date
{
    int  day;
    int  month;
    int  year;
};

int main()
{
    Date  d;

    cout << "Enter day: ";
    cin >> d.day;

    cout << "Enter month: ";
    cin >> d.month;

    cout << "Enter year: ";
    cin >> d.year;

    cout << "Date: " << d.day << "/" << d.month << "/" << d.year << endl;

    return 0;
}
