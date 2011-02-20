// ================================================== //
// -- File      : quiz1_group_a.cpp         --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 21/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// function declaration
int  stringLength(const char *str, int *pLength);

int main()
{
    const char *strName = "Ali_Veli";
    int  length;

    stringLength(strName, &length);

    cout << "stringLength(\"" << strName << "\") = " << length << endl;

    return 0;
}

// function definition
int  stringLength(const char *str, int *pLength)
{
    int  count = 0;

    // count characters until null character
    while (*str != '\0')
    {
        ++str;
        ++count;
    }

    // write count to the memory location where pLength points
    *pLength = count;

    return count;
}
