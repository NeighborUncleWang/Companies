#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string& word) {
    stringstream ss(word);
    string temp;
    vector<string> result;
    while (ss >> temp) {
        result.push_back(temp);
    }
    return result;
}

void wordDistance(string words, string word1, string word2) {
    auto strings = split(words);
    int index1 = -1;
    int index2 = -1;
    int minDistance = INT_MAX;
    pair<int, int> result(-1, -1);
    for (int i = 0; i < strings.size(); ++i) {
        if (strings[i] == word1) {
            index1 = i;
        } else if (strings[i] == word2) {
            index2 = i;
        }
        if (index1 != -1 && index2 != -1) {
            if (abs(index2 - index1) < minDistance) {
                result.first = min(index1, index2);
                result.second = max(index1, index2);
                minDistance = result.second - result.first;
            }
        }
    }
    if (result.first == -1) return;
    int startIndex = max(0, result.first - 3);
    int endIndex = min((int)strings.size() - 1, result.second + 3);
    for (int i = startIndex; i <= endIndex; ++i) {
        cout << strings[i] << " ";
    }
    cout << endl;
}

int main() {
    string words("Indeed use python and java to deal with the python python and is for java");
    wordDistance(words, "python", "java");
    return 0;
}