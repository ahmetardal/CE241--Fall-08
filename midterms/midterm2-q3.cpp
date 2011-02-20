#include <iostream>

using namespace std;

struct Student
{
    int  id;
    int  grade;
};

int main()
{
    Student  *pStuArr;
    int  stCount;

    cout << "Enter # of students: ";
    cin >> stCount;

    pStuArr = new Student[stCount];

    for (int i = 0; i < stCount; ++i)
    {
        cout << "Enter id: ";
        cin >> pStuArr[i].id;
        cout << "Enter grade: ";
        cin >> pStuArr[i].grade;
    }

    for (int i = 0; i < stCount; ++i)
    {
        pStuArr[i].grade += 10;
    }

    for (int i = 0; i < stCount; ++i)
    {
        cout << pStuArr[i].grade << endl;
    }

    delete [] pStuArr;

    return 0;
}
