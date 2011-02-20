// ================================================== //
// -- File      : q2.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 04/12/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char *str = "ali_veli";
    char *strDynamic;
    int   size;

    // get character array size
    cout << "Enter size: ";
    cin >> size;

    // allocate memory for dynamic string
    strDynamic = new char[size];

    // initialize the string by copying str to it
    strncpy(strDynamic, str, (size - 1));
    strDynamic[size - 1] = '\0';

    // print the string
    cout << strDynamic << endl;

    // deallocate the memory we allocated for the string
    delete [] strDynamic;

    return 0;
}
