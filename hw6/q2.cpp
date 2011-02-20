// ================================================== //
// -- File      : q2.cpp                    --------- //
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

// function declaration
bool  TimeIsEqual(const Time *pTime1, const Time *pTime2);

int main()
{
    Time  time1 = {12, 32, 27};
    Time  time2 = {12, 32, 28};
    Time  time3 = {12, 32, 27};

    // compare time1 and time2
    if (TimeIsEqual(&time1, &time2))
    {
        cout << "time1 and time2 are equal...";
    }
    else
    {
        cout << "time1 and time2 are not equal...";
    }
    cout << endl;

    // compare time1 and time3
    if (TimeIsEqual(&time1, &time3))
    {
        cout << "time1 and time3 are equal...";
    }
    else
    {
        cout << "time1 and time3 are not equal...";
    }
    cout << endl;

    return 0;
}

// function definition
bool  TimeIsEqual(const Time *pTime1, const Time *pTime2)
{
    return (pTime1->hour   == pTime2->hour)   &&
           (pTime1->minute == pTime2->minute) &&
           (pTime1->second == pTime2->second);
}
