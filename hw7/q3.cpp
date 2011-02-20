// ================================================== //
// -- File      : q3.cpp                    --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 04/12/2008                --------- //
// ================================================== //

#include <iostream>

using namespace std;

// struct declaration
struct ProjectMember
{
    int   memberId;
    char *memberName;
    int   contributionNHours;
};

// symbolic constants
const int  N_MEMBERS = 4;

int main()
{
    ProjectMember  members[N_MEMBERS] =
    {
        {1, "Ali",   12},
        {2, "Veli",  25},
        {3, "Hasan", 32},
        {4, "Deniz", 8 }
    };
    int  completionTime = 0;

    // calculate total project completion time
    for (int i = 0; i < N_MEMBERS; ++i)
    {
        completionTime += members[i].contributionNHours;
    }

    cout << "Total completion time is: " << completionTime << " hours." << endl;

    // print project members' names
    cout << endl << "Project members:" << endl;
    for (int i = 0; i < N_MEMBERS; ++i)
    {
        cout << members[i].memberName << endl;
    }

    return 0;
}
