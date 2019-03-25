// Read data from inputS.txt.
// Format the data
// Write to file outputS.txt

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

const int COLUMN_WIDTH = 20;

void PrintTableBody(string inputFileName, string outputFileName)
{
    ifstream input(inputFileName.c_str());
    ofstream output(outputFileName.c_str());

    if(input.is_open() && output.is_open())
    {
        output << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
        output << setw(COLUMN_WIDTH) << "" << "-+-";
        // If we delete "" then it will include endl in COLUMN WIDTH
        output << setw(COLUMN_WIDTH) << "" << endl;
        // undo the changes we made to output .
        output << setfill(' ');

        int intValue;
        double doubleValue;
        int rowNo = 1;
        while(input >> intValue >> doubleValue)
        {
            output << setw(COLUMN_WIDTH) << rowNo << " | ";
            output << setw(COLUMN_WIDTH) << intValue << " | ";
            output << setw(COLUMN_WIDTH) << intValue << endl;
            rowNo++;
        }
    }
}

int main()
{
    string inputFileName = "inputS.txt";
    string outputFileName = "outputS.txt";

    PrintTableBody(inputFileName, outputFileName);

    return 0;
}

/*
while(true) {
    int intValue;
    double doubleValue;
    input >> intValue >> doubleValue;
    if(input.fail()) break;
    // ... process values here ...
}

Equivalent to

int intValue;
double doubleValue;
while(input >> intValue >> doubleValue) {
    // ... process values here ...
}

*/
