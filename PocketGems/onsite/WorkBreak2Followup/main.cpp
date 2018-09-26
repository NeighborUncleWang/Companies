#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] >= 0 && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = j;
                    break;
                }
            }
        }
        string res;
        int index = n + 1;
        while (index != 0) {
            res = s.substr(dp[index], index - dp[index]) + " " + res;
            index = dp[index];
        }
        cout << res << endl;
        return dp.back() >= 0;
    }
};



int main() {
    cout << "Hello, World!" << endl;
    return 0;
}