// ================================================== //
// -- File      : q1.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 21/11/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// symbolic constants
const int N_COURSES = 4;
const int N_EXAMS   = 3;

// function declaration
void  calculateAverages(const int grades[][N_EXAMS], double *pAverages, int nCourses);

int main()
{
    double  averages[N_COURSES];
    int  gradesTable[N_COURSES][N_EXAMS] =
    {
        {60, 70, 80},
        {70, 80, 90},
        {80, 90, 95},
        {50, 60, 70}
    };

    // calculate averages
    calculateAverages(gradesTable, averages, N_COURSES);

    // print calculated averages
    for (int i = 0; i < N_COURSES; ++i)
    {
        cout << "Average for Course-" << (i + 1) << ": " << averages[i] << endl;
    }

    return 0;
}

// function definition
void  calculateAverages(const int grades[][N_EXAMS], double *pAverages, int nCourses)
{
    int  tmpSum;

    // traverse rows as courses
    for (int i = 0; i < nCourses; ++i)
    {
        tmpSum = 0;
        
        // calculate sum of exam grades for ith course
        for (int k = 0; k < N_EXAMS; ++k)
        {
            tmpSum += grades[i][k];
        }
        
        // calculate average of exam grades for ith course
        pAverages[i] = (double) tmpSum / N_EXAMS;
    }
}
