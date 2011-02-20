// ================================================== //
// -- File      : gradeList-Dynamic.cpp     --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 05/12/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstdlib>

using namespace std;

// struct declaration
struct GradeNode
{
    int  studId;
    int  grade;

    GradeNode *pNext;
};

int main()
{
    GradeNode  *pFirst, *pLast;
    int  listSize;

    cout << "Enter list size: ";
    cin >> listSize;

    // create the first node of the list
    pFirst = new GradeNode;
    pFirst->pNext = NULL;
    pLast = pFirst;

    // construct the remaining nodes of the list
    // loop will iterate (listSize - 1) times
    while (--listSize)
    {
        GradeNode *pTmp = new GradeNode;

        pTmp->pNext = NULL;
        pLast->pNext = pTmp;
        pLast = pTmp;
    }

    // assign grades by iterating through the list
    for (GradeNode  *pGrade = pFirst; pGrade != NULL; pGrade = pGrade->pNext)
    {
        cout << "Enter a grade(0-100):";
        cin >> pGrade->grade;
    }

    // print grades by iterating through the list
    cout << endl << "Grades:" << endl;
    for (GradeNode  *pGrade = pFirst; pGrade != NULL; pGrade = pGrade->pNext)
    {
        cout << pGrade->grade << endl;
    }
    cout << endl;

    // deallocate the GradeNode structs we allocate while constructing the list
    for (GradeNode  *pGrade = pFirst; pGrade != NULL; )
    {
        GradeNode *pNextTmp = pGrade->pNext;

        delete pGrade;
        pGrade = pNextTmp;
    }

    return 0;
}
