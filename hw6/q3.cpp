// ================================================== //
// -- File      : q3.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 27/11/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstring>

using namespace std;

// function declarations
void  printWordsReverse(const char *str);
void  printNChars(const char *str, int nChars);

int main()
{
    const char  *str = "print me now";

    printWordsReverse(str);
    cout << endl;

    return 0;
}

// function definitions
void  printWordsReverse(const char *str)
{
    int  count = 0;
    int  idx   = strlen(str) - 1;

    while (true)
    {
        if (str[idx] == ' ')
        {
            printNChars((str + idx + 1), count);
            cout << " ";
            count = 0;
        }
        else if (idx == 0)
        {
            printNChars(str, (count + 1));
            return;
        }
        else
        {
            ++count;
        }

        --idx;
    }
}

void  printNChars(const char *str, int nChars)
{
    while (nChars--)
    {
        cout << *str++;
    }
}
