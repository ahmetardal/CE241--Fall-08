#include <iostream>
#include <fstream>

using namespace std;

// struct declaration
struct Grade
{
    int  studId;
    int  grade;
};

// function declarations
void  gradeArrayToFile(const char *filePath, const Grade *pGrades, int nGrades);
void  printGradeFile(const char *filePath);
int   countGradesInGradeFile(const char *filePath);
void  sortGradeFileById(const char *filePath, const char *sortedFilePath);
void  sortGradeArrById(Grade *pGrades, int nGrades);

int main()
{
    const int  N_GRADES = 5;
    const char  *gradeFilePath = "grades.txt";
    const char  *sortedGradeFilePath = "grades-sorted.txt";
    Grade  grades[N_GRADES] = {{5, 55}, {4, 44}, {3, 33}, {2, 22}, {1, 11}};

    // write grades to file
    gradeArrayToFile(gradeFilePath, grades, N_GRADES);

    cout << "original grade file:" << endl;
    printGradeFile(gradeFilePath);

    // count how many grades exist in the file
    cout << endl << "# of grades: " << countGradesInGradeFile(gradeFilePath) << endl;

    // sort grades and write them to another file
    sortGradeFileById(gradeFilePath, sortedGradeFilePath);

    cout << endl << "sorted grade file:" << endl;
    printGradeFile(sortedGradeFilePath);

    return 0;
}

// function definitions
void  gradeArrayToFile(const char *filePath, const Grade *pGrades, int nGrades)
{
    ofstream  ofs(filePath);

    // check whether file is created successfully
    if (!ofs)
    {
        cerr << "Error: Cannot create file..." << endl;
        return;
    }

    // write each grade to file
    for (int i = 0; i < nGrades; ++i)
    {
        ofs << pGrades[i].studId << '\t' << pGrades[i].grade << endl;
    }

    // close the file
    ofs.close();
}

void  printGradeFile(const char *filePath)
{
    Grade  g;
    ifstream  ifs(filePath);

    // check whether file is opened successfully
    if (!ifs)
    {
        cerr << "Error: Cannot open file..." << endl;
        return;
    }

    while (true)
    {
        // read a studId and a grade from file into g
        ifs >> g.studId >> g.grade;

        // check whether we reached the end of the file
        if (ifs.eof())
        {
            break;
        }

        // print g's id and grade members
        cout << "student id: " << g.studId << ", grade: " << g.grade << endl;
    }

    // close the file
    ifs.close();
}

int  countGradesInGradeFile(const char *filePath)
{
    Grade  g;
    ifstream  ifs(filePath);    // input file grades
    int  count = 0;

    // check whether file is opened successfully
    if (!ifs)
    {
        cerr << "Error: Cannot open file..." << endl;
        return -1;
    }

    while (true)
    {
        // try to read one grade from file
        ifs >> g.studId >> g.grade;

        // check whether we reached the end of the file
        if (ifs.eof())
        {
            break;
        }

        // until we reach the end of the file, increment count
        ++count;
    }

    // close the file
    ifs.close();

    return count;
}

void  sortGradeFileById(const char *filePath, const char *sortedFilePath)
{
    // get number of grades the file named filePath contains
    int  nGrades = countGradesInGradeFile(filePath);

    if (nGrades <= 0)
    {
        cerr << "Error: No grades available to read..." << endl;
        return;
    }

    // create a dynamic array of size nGrades
    Grade  *pGrArr = new Grade[nGrades];
    ifstream  ifs(filePath);    // input file grades

    // check whether file is opened successfully
    if (!ifs)
    {
        cerr << "Error: Cannot open file..." << endl;
        return;
    }

    // read nGrades many grades from the file and store each in the array
    for (int i = 0; i < nGrades; ++i)
    {
        ifs >> pGrArr[i].studId >> pGrArr[i].grade;
    }
    // close the file
    ifs.close();

    // sort grade array by id
    sortGradeArrById(pGrArr, nGrades);

    // create a file to write sorted grade array
    ofstream  ofs(sortedFilePath);

    // check whether file is created successfully
    if (!ofs)
    {
        cerr << "Error: Cannot create file..." << endl;
        return;
    }

    // write each grade to file
    for (int i = 0; i < nGrades; ++i)
    {
        ofs << pGrArr[i].studId << '\t' << pGrArr[i].grade << endl;
    }

    // close the file and delete the dynamic array
    ofs.close();
    delete [] pGrArr;
}

void  sortGradeArrById(Grade *pGrades, int nGrades)
{
    Grade  tmpGrade;

    // sort the grade array by id field using bubble sort sorting algorithm
    for (int i = 0; i < (nGrades - 1); ++i)
    {
        for(int k = 0; k < (nGrades - i - 1); ++k)
        {
            if (pGrades[k].studId > pGrades[k + 1].studId)
            {
                tmpGrade = pGrades[k];
                pGrades[k] = pGrades[k + 1];
                pGrades[k + 1] = tmpGrade;
            }
        }
    }
}
