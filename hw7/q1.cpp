// ================================================== //
// -- File      : q1.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 04/12/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// function declaration
void  printArrayInt(const int *pArray, int size);

int main()
{
    int  *pArray;
    int   arraySize;

    // initialize random number generation library's seed value
    srand((unsigned int) time(0));

    // get array size
    cout << "Enter array size: ";
    cin >> arraySize;

    // allocate memory for dynamic array
    pArray = new int[arraySize];

    // initialize the array with random values
    for (int i = 0; i < arraySize; ++i)
    {
        pArray[i] = rand() % 100;
    }

    // print the array content
    printArrayInt(pArray, arraySize);
    cout << endl;

    // deallocate the memory we allocated for the array
    delete [] pArray;

    return 0;
}

// function definition
void  printArrayInt(const int *pArray, int size)
{
    while (size--)
    {
        cout << *pArray++ << " ";
    }
}
