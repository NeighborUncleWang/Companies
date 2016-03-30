#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream myfile;
    myfile.open("/Users/lixianshu/PycharmProjects/univerisities.txt");
    string temp;
    ofstream outputFile;
    outputFile.open("/Users/lixianshu/ClionProjects/ModifyUniveristiesDatabase/output.txt");
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