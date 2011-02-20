#include <iostream>

using namespace std;

struct GradeNode
{
    int  id;
    int  grade;
    GradeNode  *pNext;
};

GradeNode  *gradeListToArray(const GradeNode *pHead, int *pArrLength);
GradeNode  *gradeArrayToList(const GradeNode gradeArr[], int arrLength);
GradeNode  *newGradeNode(int id, int grade);
void        appendGrade(GradeNode *pHead, int id, int grade);
void        destroyGradeList(GradeNode *pHead);

int main()
{
    GradeNode  g1 = {1, 30, NULL};
    GradeNode  g2 = {2, 40, NULL};
    GradeNode  g3 = {3, 60, NULL};

    g1.pNext = &g2;
    g2.pNext = &g3;
    g3.pNext = NULL;

    // convert list to array
    int  arrLength;
    GradeNode  *pGrArr = gradeListToArray(&g1, &arrLength);

    cout << "printing array..." << endl;
    for (int i = 0; i < arrLength; ++i)
    {
        cout << pGrArr[i].id << ", ";
        cout << pGrArr[i].grade << endl;
    }

    // convert array to list
    GradeNode  *pHead = gradeArrayToList(pGrArr, arrLength);
    
    cout << "printing list..." << endl;
    for (GradeNode *pNode = pHead; pNode != NULL; pNode = pNode->pNext)
    {
        cout << pNode->id << ", " << pNode->grade << endl;
    }

    // destroy both list and array
    destroyGradeList(pHead);
    delete [] pGrArr;
    
    return 0;
}

GradeNode  *gradeListToArray(const GradeNode *pHead, int *pArrLength)
{
    GradeNode  *pGradeArr;
    int  count = 0;

    // count items of the list
    for (const GradeNode *pNode = pHead; pNode != NULL; pNode = pNode->pNext)
    {
        ++count;
    }

    // assign count to where pArrLength points
    *pArrLength = count;
    // create a dynamic array of size "count"
    pGradeArr = new GradeNode[count];

    // copy values from list to array
    for (int i = 0; i < count; pHead = pHead->pNext, ++i)
    {
        pGradeArr[i].id    = pHead->id;
        pGradeArr[i].grade = pHead->grade;
    }

    // return dynamic array's address
    return pGradeArr;
}

GradeNode  *gradeArrayToList(const GradeNode gradeArr[], int arrLength)
{
    // create first item of the list
    GradeNode  *pHead = newGradeNode(gradeArr[0].id, gradeArr[0].grade);

    // create the rest of the list
    for (int i = 1; i < arrLength; ++i)
    {
        appendGrade(pHead, gradeArr[i].id, gradeArr[i].grade);
    }

    // return the address of the list
    return pHead;
}

GradeNode  *newGradeNode(int id, int grade)
{
    GradeNode  *pGradeNode = new GradeNode;
    
    pGradeNode->id    = id;
    pGradeNode->grade = grade;
    pGradeNode->pNext = NULL;
    
    return pGradeNode;
}

void  appendGrade(GradeNode *pHead, int id, int grade)
{
    if (pHead == NULL)
    {
        return;
    }

    GradeNode  *pNewGradeNode = newGradeNode(id, grade);
    GradeNode  *pNode;

    for (pNode = pHead; ; pNode = pNode->pNext)
    {
        if (pNode->pNext == NULL)
        {
            break;
        }
    }

    pNode->pNext = pNewGradeNode;
}

void  destroyGradeList(GradeNode *pHead)
{
    // destroy the list and free all dynamically allocated memory
    for (GradeNode *pNode = pHead; pNode != NULL; )
    {
        GradeNode  *pTmpNode = pNode->pNext;
        
        delete pNode;
        pNode = pTmpNode;
    }
}

