// ================================================== //
// -- File      : quiz2_group_b.cpp         --------- //
// -- Author    : Ahmet ARDAL               --------- //
// -- Contact   : ardalahmet@hotmail.com    --------- //
// -- Date      : 27/11/2008                --------- //
// ================================================== //

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// struct declaration
struct AquaTemperature
{
    int  aquariumId;
    int  temperature;
};

// symbolic constants
const int  N_AQUARIUMS = 30;

int main()
{
    AquaTemperature  aquaTempsList[N_AQUARIUMS];
    double  averageTemp;
    int     tempsSum = 0;

    // initialize random number generation library's seed value
    srand((unsigned int) time(0));

    // randomly generate aquarium ids and temperatures
    for (int i = 0; i < N_AQUARIUMS; ++i)
    {
        aquaTempsList[i].aquariumId  = rand();
        aquaTempsList[i].temperature = rand() % 50;
    }

    // sum all temperatures
    for (int i = 0; i < N_AQUARIUMS; ++i)
    {
        tempsSum += aquaTempsList[i].temperature;
    }

    // calculate and print the average
    averageTemp = (double) tempsSum / N_AQUARIUMS;
    cout << "Average temperature is: " << averageTemp << endl;

    return 0;
}
