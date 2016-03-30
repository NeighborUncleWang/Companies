#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    fstream myfile;
    myfile.open("/Users/lixianshu/PycharmProjects/univerisities.txt");
    string temp;
    fstream outputFile;
    outputFile.open("./output.txt");
    int count = 0;
    string modifiedSchoolName;
    while (getline(myfile, temp, '\n')) {
        ++count;
        modifiedSchoolName = '\"' + temp + "\"," + '\n';
        cout << modifiedSchoolName;
        outputFile << modifiedSchoolName;
    }
    outputFile.close();
    cout << count;
    return 0;
}