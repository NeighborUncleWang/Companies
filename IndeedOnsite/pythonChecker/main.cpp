#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int countLeadingSpaces(string& str) {
    return str.find_first_not_of(" ");
}

bool endWithColon(string& str) {
    return str.back() == ':';
}

bool pythonChecker(string fileName) {
    fstream myFile(fileName);
    string temp;
    vector<string> lines;
    while (getline(myFile, temp)) {
        lines.push_back(temp);
    }
    stack<int> st;
    bool colon = false;
    for (int i = 0; i < lines.size(); ++i) {
        int count = countLeadingSpaces(lines[i]);
        if (colon) {
            if (st.empty() || count <= st.top()) {
                return i;
            } else {
                st.push(count);
            }
        } else {
            if (st.empty()) {
                st.push(count);
            } else if (count > st.top()) {
                return i;
            } else {
                while (!st.empty() && count != st.top()) {
                    st.pop();
                }
                if (st.empty()) {
                    return i;
                }
            }
        }
        colon = endWithColon(lines[i]);
    }
    return -1;
}

int main() {
    cout << pythonChecker("/Users/lixianshu/ClionProjects/IndeedOnsite/pythonChecker/001.py") << endl;
    return 0;
}