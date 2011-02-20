// ================================================== //
// -- File      : gradeList.cpp             --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 05/12/2008                --------- //
// ================================================== //

#include <iostream>

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
    GradeNode  g1, g2, g3, g4;

    // construct the list
    g1.pNext = &g2;
    g2.pNext = &g3;
    g3.pNext = &g4;
    g4.pNext = NULL;

    // assign values to grades by iterating through the list
    for (GradeNode *pGrade = &g1; pGrade != NULL; pGrade = pGrade->pNext)
    {
        pGrade->grade = 90;
    }

    cout << "Grades: " << endl;
    // print grades by iterating through the list
    for (GradeNode *pGrade = &g1; pGrade != NULL; pGrade = pGrade->pNext)
    {
        cout << pGrade->grade << endl;
    }
    cout << endl;

    return 0;
}
