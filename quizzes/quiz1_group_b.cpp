// ================================================== //
// -- File      : quiz1_group_b.cpp         --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 21/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// function declaration
void  strReplaceChar2(char *str, char oldChar1, char newChar1, char oldChar2, char newChar2);

int main()
{
    char str[] = "ankara_adana";

    cout << "Original string: " << str << endl;
    strReplaceChar2(str, 'a', 'X', 'n', 'Z');
    cout << "Modified string: " << str << endl;

    return 0;
}

// function definition
void  strReplaceChar2(char *str, char oldChar1, char newChar1, char oldChar2, char newChar2)
{
    // iterate through characters of str
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == oldChar1)
        {
            // if current character is oldChar1 then replace it with newChar1
            str[i] = newChar1;
        }
        else if (str[i] == oldChar2)
        {
            // if current character is oldChar2 then replace it with newChar2
            str[i] = newChar2;
        }
    }
}
