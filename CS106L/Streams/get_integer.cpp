// Read input until user enters valid int data
#include<iostream>
#include<sstream>

using namespace std;

string GetLine()
{
    string data;
    getline(cin, data);
    return data;
}

int GetInteger()
{
    while(true)
    {
        stringstream parser;
        parser << GetLine();

        // Entered data
        cout<< "Your Input : " << parser.str() << endl;

        int requiredValue;
        if(parser >> requiredValue)
        {
            char residualData;

            if(parser >> residualData)
            {
                // Having extra data
                cout<< "Unexpected character: " << residualData << endl;
                continue;
            }
            else
                return requiredValue;
        }
        else
        {
            // Not valid data, try again
            cout<< "Please retry : Invalid data" << endl;
            continue;
        }
    }
}

int main()
{
    cout<< GetInteger() << endl;
    return 0;
}
