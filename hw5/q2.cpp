// ================================================== //
// -- File      : q2.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 21/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// function declaration
int  stringLength(const char *str);

int main()
{
    const char *strName = "Ali_Veli";

    cout << "stringLength(\"" << strName << "\") = " << stringLength(strName) << endl;

    return 0;
}

// function definition
int  stringLength(const char *str)
{
    int  count = 0;

    //while (*str++)
    //{
    //    ++count;
    //}

    //while (*str)
    //{
    //    ++str;
    //    ++count;
    //}

    //while (*str++ != '\0')
    //{
    //    ++count;
    //}

    // count characters until null character
    while (*str != '\0')
    {
        ++str;
        ++count;
    }

    return count;
}
