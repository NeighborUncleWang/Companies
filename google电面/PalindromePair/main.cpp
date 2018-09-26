#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<string, string> > palindomPair(vector<string> &words) {
        vector<pair<string, string> > rst;
        unordered_set<string> dict;
//        for (int i = 0; i < words.size(); i++) {
//            dict.insert(words[i]);
//        }
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].size();
            for (int l = 0; l < len; l++) {
                string sub1 = words[i].substr(0, l);
                string sub2 = words[i].substr(l, len - l);
                if (isPal(sub2)) {
                    string tmp = sub1;
                    reverse(tmp.begin(), tmp.end());
                    if (dict.find(tmp) != dict.end()) {
                        rst.push_back(pair<string, string>(words[i], tmp));
                    }
                }
                if (isPal(sub1)) {
                    string tmp = sub2;
                    reverse(tmp.begin(), tmp.end());
                    if (dict.find(tmp) != dict.end()) {
                        rst.push_back(pair<string, string>(tmp, words[i]));
                    }
                }
            }
            dict.insert(words[i]);
        }
        return rst;
    }
private:
    bool isPal(string& s) {
        int size = s.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};


int main() {
    vector<string> words{"abcd", "dcba", "lls", "s", "sssll"};
    sort(words.begin(), words.end(), [](string& lhs, string& rhs) {return lhs.size() < rhs.size(); });
    Solution a;
    auto result = a.palindomPair(words);
    for (auto& iter : result) {
        cout << iter.first << " " << iter.second << endl;
    }
    return 0;
}