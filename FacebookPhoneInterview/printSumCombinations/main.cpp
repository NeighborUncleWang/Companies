#include <iostream>
#include <vector>

using namespace std;

struct Solution {
    vector<string> printSumCombinations(int n) {
        vector<string> result;
        dfs(result, "", 1, 0, n);
        return result;
    }
    void dfs(vector<string>& result, string combination, int currentNumber, int sum, int n) {
        if (sum == n) {
            result.push_back(combination.substr(0, combination.size() - 1));
            return;
        }
        for (int i = currentNumber; i <= n && i <= n - sum; ++i) {
            dfs(result, combination + to_string(i) + "+", i, sum + i, n);
        }
    }
};


int main() {
    Solution a;
    auto result = a.printSumCombinations(10);
    for (auto& s : result) {
        cout << s << endl;
    }
    return 0;
}