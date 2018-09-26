#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int PickMost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 4, vector<int>(n + 4, 0));
        for (int len = 1; len <= n; ++len) {
            for (int start = 2; start + len - 1 < n + 2; ++start) {
                int end = start + len - 1;
                dp[start][end] = max(nums[start - 2] + min(dp[start + 1][end - 1], dp[start + 2][end]),
                nums[end - 2] + min(dp[start][end - 2], dp[start + 1][end - 1]));
            }
        }
        return dp[2][n + 1];
//        vector<vector<int>> dp(n, vector<int>(n, 0));
//        for (int len = 1; len <= n; ++len) {
//            for (int start = 0; start + len - 1 < n; ++start) {
//                int end = start + len - 1;
//                dp[start][end] = max(nums[start] + min(get(dp, start + 1, end - 1), get(dp, start + 2, end)),
//                nums[end] + min(get(dp, start, end - 2), get(dp, start + 1, end - 1)));
//            }
//        }
//        return dp[0][n - 1];
    }

private:
    int get(vector<vector<int>>& dp, int start, int end) {
        return start > end ? 0 : dp[start][end];
    }
};

int main() {
    Solution a;
    vector<int> nums{3, 9, 1, 2};
    cout << a.PickMost(nums) << endl;
    return 0;
}