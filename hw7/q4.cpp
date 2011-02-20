// ================================================== //
// -- File      : q4.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 04/12/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstring>

using namespace std;

// struct declaration
struct BirthDate
{
    char *nameOfFriend;
    int   day;
    int   month;
    int   year;
};

// function declaration
int  findBirthDateByName(const BirthDate *pBirthDates, int size, const char *name);

// symbolic constants
const int  N_BIRTHDATES = 5;

int main()
{
    BirthDate  birthDates[N_BIRTHDATES] =
    {
        {"Ali",   1, 2, 1980},
        {"Veli",  3, 4, 1982},
        {"Hasan", 5, 6, 1984},
        {"Yeliz", 7, 8, 1986},
        {"Kaan",  9, 1, 1988}
    };
    int  idx;

    idx = findBirthDateByName(birthDates, N_BIRTHDATES, "Yeliz");
    if (idx == -1)
    {
        cout << "cannot find name..." << endl;
    }
    else
    {
        cout << "name found... birth date is: ";
        cout
            << birthDates[idx].day
            << "/"
            << birthDates[idx].month
            << "/"
            << birthDates[idx].year
            << endl;
    }

    idx = findBirthDateByName(birthDates, N_BIRTHDATES, "Deniz");
    if (idx == -1)
    {
        cout << "cannot find name..." << endl;
    }
    else
    {
        cout << "name found... birth date is: ";
        cout
            << birthDates[idx].day
            << "/"
            << birthDates[idx].month
            << "/"
            << birthDates[idx].year
            << endl;
    }

    return 0;
}

// function definition
int  findBirthDateByName(const BirthDate *pBirthDates, int size, const char *name)
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(pBirthDates[i].nameOfFriend, name) == 0)
        {
            return i;
        }
    }

    return -1;
}
