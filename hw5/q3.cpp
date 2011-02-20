// ================================================== //
// -- File      : q3.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 21/11/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstring>

using namespace std;

// function declaration
bool  isPalindromeRec(const char *str, int leftIdx, int rightIdx);

int main()
{
    const char *strPal = "desserts | stressed";

    if (isPalindromeRec(strPal, 0, (strlen(strPal) - 1)))
    {
        cout << "'" << strPal << "' is a palindrome...";
    }
    else
    {
        cout << "'" << strPal << "' is not a palindrome...";
    }

    cout << endl;

    return 0;
}

// function definition
bool  isPalindromeRec(const char *str, int leftIdx, int rightIdx)
{
    // base case
    if (leftIdx > rightIdx)
    {
        return true;
    }

    // general case
    if (str[leftIdx] == str[rightIdx])
    {
        return isPalindromeRec(str, (leftIdx + 1), (rightIdx - 1));
    }

    return false;
}
