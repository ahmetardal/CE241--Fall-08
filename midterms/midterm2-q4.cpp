#include <iostream>

using namespace std;

struct Student
{
    int  id;
    int  grade;
    Student  *pNext;
};

void  printListRev(const Student *pHead);
int   countGradesLessThan50(const Student *pHead);

int main()
{
    Student  s1 = {1, 30, NULL};
    Student  s2 = {2, 40, NULL};
    Student  s3 = {3, 60, NULL};

    s1.pNext = &s2;
    s2.pNext = &s3;
    s3.pNext = NULL;

    cout << countGradesLessThan50(&s1) << endl;
    printListRev(&s1);

    return 0;
}

void  printListRev(const Student *pHead)
{
    if (pHead == NULL)
    {
        return;
    }

    printListRev(pHead->pNext);
    cout << pHead->grade << endl;
}

int  countGradesLessThan50(const Student *pHead)
{
    if (pHead == NULL)
    {
        return 0;
    }

    if (pHead->grade < 50)
    {
        return countGradesLessThan50(pHead->pNext) + 1;
    }
    else
    {
        return countGradesLessThan50(pHead->pNext);
    }
}
