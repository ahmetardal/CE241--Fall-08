// ================================================== //
// -- File      : q4.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 21/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// function declaration
void  strCopyReplace(const char *src, char *dest, char oldChar, char newChar);

int main()
{
    const char *strSrc = "ankara_adana";
    char strDest[20];

    strCopyReplace(strSrc, strDest, 'a', 'X');

    cout << "Original string: " << strSrc << endl;
    cout << "Modified string: " << strDest << endl;

    return 0;
}

// function definition
void  strCopyReplace(const char *src, char *dest, char oldChar, char newChar)
{
    int  i;

    // copy the string from src to dest
    for (i = 0; src[i] != '\0'; ++i)
    {
        // if current character is oldChar then copy newChar instead of it,
        // otherwise just copy it...
        if (src[i] == oldChar)
        {
            dest[i] = newChar;
        }
        else
        {
            dest[i] = src[i];
        }
    }

    // put null character to finalize the string
    dest[i] = '\0';
}
