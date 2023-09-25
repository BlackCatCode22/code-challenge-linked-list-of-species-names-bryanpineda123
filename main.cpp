#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    fstream myFile;
    myFile.open("C:\\Users\\BE129\\Desktop\\animalNames.txt", ios::in);//read REMEMBER TO REDIRECT PATH TO YOUR LOCAL MEMORY

    string fileContents;

    if(myFile.is_open())
    {
        string line;
        while(getline(myFile, line))
        {
            fileContents += line + '\n';
        }
        myFile.close();
    }

    cout << fileContents;
    int position = fileContents.find("Hyena");
    int position2 = fileContents.find("Lion");
    int position3 = fileContents.find("Bear");
    int position4 = fileContents.find("Tiger");
    cout << position << " and " << position2 << " and " << position3 << " and " << position4 << endl;

    int hyenaLineNumber = 0;
    int lineNumber = 0;


    return 0;
}
