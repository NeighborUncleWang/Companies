#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int targetSumDP(int n) {
        //use knapsack
        int target = (1 + n) * n / 4;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int sum = 1; sum <= target; ++sum) {
                if (i > sum) {
                    dp[i][sum] = dp[i - 1][sum];
                } else {
                    dp[i][sum] = dp[i - 1][sum] + dp[i - 1][sum - i];
                }
            }
        }
        return dp.back().back() / 2;
    }
    int targetSum(int n) {
        int target = (1 + n) * n / 4;
        int count = 0;
        vector<int> combination;
        vector<vector<int>> result;
        helper(result, combination, n, 1, target, count);
        for (auto& vec : result) {
            for (int num : vec) {
                cout << num << " ";
            }
            cout << endl;
        }
        return count;
    }

private:
    void helper(vector<vector<int>>& result, vector<int>& combination, int n,
                int currentNum, int target, int& count) {
        if (target == 0) {
            result.push_back(combination);
            ++count;
            return;
        }
        for (int i = currentNum; i <= n && i <= target; ++i) {
            combination.push_back(i);
            helper(result, combination, n, i + 1, target - i, count);
            combination.pop_back();
        }
    }
};


int main() {
    Solution a;
    //target = 7*8/4 = 14
    a.targetSum(7);
    cout << a.targetSumDP(7);
    return 0;
}