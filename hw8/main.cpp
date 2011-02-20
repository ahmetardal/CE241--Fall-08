#include <iostream>

using namespace std;

// struct declaration
struct GradeNode
{
    int  id;
    int  grade;
    GradeNode  *pNext;
};

// --------------------------------------------
// --- function declarations ------------------
// --------------------------------------------
GradeNode  *newGradeNode(int id, int grade);
void        appendGrade(GradeNode *pHead, int id, int grade);
GradeNode  *findGradeById(const GradeNode *pHead, int id);
void        printGradeList(const GradeNode *pHead);
GradeNode  *deleteFirstGrade(GradeNode *pHead);
void        destroyGradeList(GradeNode *pHead);

int main()
{
    GradeNode  *pHead;  // pointer to the first item in the list

    // create the first node of the list
    pHead = new GradeNode;
    pHead->id = 77;
    pHead->grade = 70;
    pHead->pNext = NULL;

    // use appendGrade() function to add items to the list
    for (int i = 0; i < 5; ++i)
    {
        appendGrade(pHead, i, (i * i));
    }

    // use findGradeById() function to find a specific grade in the list
    GradeNode  *pNode = findGradeById(pHead, 3);
    if (pNode == NULL)
    {
        cout << "cannot find grade with id: " << 3 << endl;
    }
    else
    {
        cout << "grade found: " << pNode->grade << endl;
    }

    // use findGradeById() function to find a specific grade in the list
    pNode = findGradeById(pHead, 300);
    if (pNode == NULL)
    {
        cout << "cannot find grade with id: " << 300 << endl;
    }
    else
    {
        cout << "grade found: " << pNode->grade << endl;
    }

    // use printGradeList() function to print grades in the list
    cout << endl << "printing the list: " << endl;
    printGradeList(pHead);

    // use deleteFirstGrade() function to delete top two items from the list,
    // and print the list to see whether deletions were successful
    pHead = deleteFirstGrade(pHead);
    pHead = deleteFirstGrade(pHead);
    cout << endl << "printing the list after deletions: " << endl;
    printGradeList(pHead);

    // destroy the list and free all dynamically allocated memory
    destroyGradeList(pHead);

    return 0;
}

// --------------------------------------------
// --- function implementations ---------------
// --------------------------------------------
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

GradeNode  *findGradeById(const GradeNode *pHead, int id)
{
    for (GradeNode *pNode = (GradeNode *) pHead; pNode != NULL; pNode = pNode->pNext)
    {
        if (pNode->id == id)
        {
            return pNode;
        }
    }

    return NULL;
}

void  printGradeList(const GradeNode *pHead)
{
    for (const GradeNode *pNode = pHead; pNode != NULL; pNode = pNode->pNext)
    {
        cout << "id: " << pNode->id << ", grade: " << pNode->grade << endl;
    }
}

GradeNode  *deleteFirstGrade(GradeNode *pHead)
{
    GradeNode  *pNewHead = pHead->pNext;

    delete pHead;
    return pNewHead;
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
