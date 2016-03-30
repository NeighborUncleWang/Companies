#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

void GenerateTestCases() {
    fstream myfile;
    myfile.open("/Users/lixianshu/ClionProjects/GenerateTestCasesForEqualsTester/result.txt");
    cout << myfile.is_open() << endl;
    vector<string> types = {"Object", "C", "D"};
    string test = "if (x.equals(y) && y.equals(z)) {\n  assertTrue(x.equals(z));\n}\n}\n";
//    cout << test;
    unordered_map<string, string> hashMap{
            {"Object", " = new Object();\n"},
            {"C", " = new C(1);\n"},
            {"D", " = new D(1, 1);\n"},
    };
    int i = 1;
    string text;
    for (string& x : types) {
        for (string& y : types) {
            for (string& z : types) {
                if (i == 1) {
                    text = "@Test\npublic void t1() {\nObject x = new Object();\nObject y = x;\nObject z = x;\n" + test;
                } else {
                    text = "@Test\npublic void t" + to_string(i) + "() {\n";
                    text += x + " x" + hashMap[x];
                    text += y + " y" + hashMap[y];
                    text += z + " z" + hashMap[z];
                    text += test;
                }
                myfile << text << endl;
                ++i;
                text.clear();
            }
        }
    }
    myfile.close();
}


int main() {
    GenerateTestCases();
    return 0;
}