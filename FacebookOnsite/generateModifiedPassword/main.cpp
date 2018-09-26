#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generateAlternatives(string& password, unordered_map<char, string>& hashMap) {
        vector<string> result;
        dfs(password, hashMap, result, 0);
        return result;
    }
    void print(vector<string>& result) {
        for (string& s : result) {
            cout << s << " ";
        }
        cout << endl;
    }
//    vector<string> iterative(string& password, unordered_map<char, string>& hashMap) {
//        vector<string> result{password};
//        for (int i = 0; i < password.size(); ++i) {
//            vector<string> temp = result;
//            for (string& s : result) {
//                for (char ch : hashMap[s[i]]) {
//                    s[i] = ch;
//                    temp.push_back(s);
//                }
//            }
//            result = move(temp);
//        }
//        return result;
//    }

    vector<string> iterative(string& password, unordered_map<char, string>& hashMap) {
        vector<string> result{password};
        for (int i = 0; i < password.size(); ++i) {
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                string s = result[j];
                for (char ch : hashMap[s[i]]) {
                    s[i] = ch;
                    result.push_back(s);
                }
            }
        }
        return result;
    }
private:
    void dfs(string& password, unordered_map<char, string>& hashMap, vector<string>& result, int index) {
        if (index == password.size()) {
            result.push_back(password);
            return;
        }
        dfs(password, hashMap, result, index + 1);
        char oldValue = password[index];
        for (char ch : hashMap[oldValue]) {
            password[index] = ch;
            dfs(password, hashMap, result, index + 1);
        }
        password[index] = oldValue;
    }
};


int main() {
    Solution a;
    unordered_map<char, string> hashMap{{'a', "@*0"}, {'s', "$"}};
    string password = "password";
    auto result = a.generateAlternatives(password, hashMap);
    a.print(result);
    result = a.iterative(password, hashMap);
    a.print(result);
    return 0;
}