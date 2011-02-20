#include <iostream>

using namespace std;

int  strLenIter(const char *str);
int  strLenRec(const char *str);

int main()
{
    char  str[] = "ankara";

    cout << "strLenIter(\"" << str << "\") = " << strLenIter(str) << endl;
    cout << "strLenRec(\"" << str << "\") = "  << strLenRec(str)  << endl;

    return 0;
}

int  strLenIter(const char *str)
{
    int  count = 0;

    while (*str++ != '\0')
    {
        ++count;
    }
    return count;
}

int  strLenRec(const char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    return strLenRec(str + 1) + 1;
}
