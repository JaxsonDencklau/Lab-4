
/*
Jaxson Dencklau
Computer Science
Temperature Project
10/22/2026

This code takes temperature inputs ranging from -30 to 120
from a file and displays them as a chart.
Each star represents 3 degrees of temperature.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

float test;

int negative(float test);
int positive(float test);

int main()
{
    // Preconditions: TempIN.txt exists and contains temperature values to process.

    // Opening the input file.
    ifstream inputfile;
    inputfile.open("C:/Users/Jdenc/source/repos/Lab 4/TempIN.txt");

    // Checking whether the file opened successfully.
    if (!inputfile)
    {
        cout << "Cannot open file" << endl;
        return 1;
    }

    // Displaying the temperature chart.
    cout << "Temperature Chart" << endl;
    cout << "         -30 -20-10  0  10 20  30 40 50  60 70 80 90 100 110 120" << endl;

    // Reading temperatures from the file.
    while (inputfile >> test)
    {
        // Checking whether the temperature is in range.
        if (test < -30 || test > 120)
        {
            cout << "Invalid input: " << test << endl;
            inputfile.close();
            return 2;
        }

        if (test < 0)
        {
            negative(test);
        }
        else
        {
            positive(test);
        }
    }

    inputfile.close();

    // Postconditions: All valid temperatures are displayed in the chart, and the input file is closed.
    return 0;
}

int negative(float test)
{
    // Preconditions: test is a negative temperature between -30 and 0 degrees.

    // Calculating the number of stars.
    int terminal = abs(test) / 3;
    string temperature(terminal, '*');

    // Displaying negative temperatures.
    cout << setw(6) << setprecision(5) << test << ": ";
    cout << setw(13) << temperature << "|" << endl;

    // Postconditions: The negative temperature and its chart representation are displayed.
    return 0;
}

int positive(float test)
{
    // Preconditions: test is a nonnegative temperature between 0 and 120 degrees.

    // Calculating the number of stars.
    int terminal = test / 3;
    string temperature(terminal, '*');

    // Displaying positive temperatures.
    cout << setw(6) << setprecision(5) << test << ": ";
    cout << setw(14) << "|" << temperature << endl;

    // Postconditions: The nonnegative temperature and its chart representation are displayed.
    return 0;
}
