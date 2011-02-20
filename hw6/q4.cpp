// ================================================== //
// -- File      : q4.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 27/11/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// struct declaration
struct Grade
{
    int  studentId;
    int  grade;
};

// symbolic constants
const int  N_STUDENTS = 30;

int main()
{
    Grade   gradesList[N_STUDENTS];
    double  average;
    int     gradesSum = 0;

    // initialize random number generation library's seed value
    srand((unsigned int) time(0));

    // randomly generate student ids and grades
    for (int i = 0; i < N_STUDENTS; ++i)
    {
        gradesList[i].studentId = rand();
        gradesList[i].grade     = rand() % 101;
    }

    // sum all grades
    for (int i = 0; i < N_STUDENTS; ++i)
    {
        gradesSum += gradesList[i].grade;
    }

    // calculate and print the average
    average = (double) gradesSum / N_STUDENTS;
    cout << "Average is:" << average << endl;

    return 0;
}
