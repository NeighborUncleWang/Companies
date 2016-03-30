#include <iostream>
#include <vector>

using namespace std;


vector<char> FindMostFrequentChar(string& s) {
    vector<char> result;
    int n = s.size();
    if (n == 0) return vector<char>();
    int count = 1;
    int max = 1;
    char candidate = s[0];
    for (int i = 1; i <= n; ++i) {
        if (i < n && s[i] == candidate) {
            ++count;
        } else {
            if (count == max) {
                result.push_back(candidate);
            } else if (count > max) {
                max = count;
                result.clear();
                result.push_back(candidate);
            }
            if (i < n) {
                candidate = s[i];
            }
            count = 1;
        }
    }
    return result;
}

vector<char> FindMostFrequentChar2(string& s) {
    vector<char> result;
    int n = s.size();
    if (n == 0) return vector<char>();
    int count = 1;
    int max = 1;
    for (int i = 1; i <=n; ++i) {
        if (i < n && s[i] == s[i - 1]) {
            ++count;
        } else {
            if (count == max) {
                result.push_back(s[i - 1]);
            } else if (count > max) {
                max = count;
                result.clear();
                result.push_back(s[i - 1]);
            }
            count = 1;
        }
    }
    return result;
}


int main() {
    string s = "thiisiisgoodd";
    for (char ch : FindMostFrequentChar(s)) {
        cout << ch << " ";
    }
    cout << endl;
    s = "thiiisiisgoodd";
    for (char ch : FindMostFrequentChar(s)) {
        cout << ch << " ";
    }
    cout << endl;
    s = "this";
    for (char ch : FindMostFrequentChar(s)) {
        cout << ch << " ";
    }
    cout << endl;


    s = "thiisiisgoodd";
    for (char ch : FindMostFrequentChar2(s)) {
        cout << ch << " ";
    }
    cout << endl;
    s = "thiiisiisgoodd";
    for (char ch : FindMostFrequentChar2(s)) {
        cout << ch << " ";
    }
    cout << endl;
    s = "this";
    for (char ch : FindMostFrequentChar2(s)) {
        cout << ch << " ";
    }
    cout << endl;
    s= "a";
    for (char ch : FindMostFrequentChar2(s)) {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}