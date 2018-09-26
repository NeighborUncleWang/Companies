#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int takeCoins(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size - 1; ++i) {
            dp[i][i + 1] = max(nums[i], nums[i + 1]);
        }
        for (int length = 4; length <= size; length += 2) {
            for (int i = 0; i + length - 1 < size; ++i) {
                int j = i + length - 1;
                dp[i][j] = max(nums[i] + max(dp[i + 1][j - 1], dp[i + 2][j]),
                               nums[j] + max(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
        return dp[0][size - 1];
    }
};


int main() {
    Solution a;
    vector<int> nums{4, 2, 10, 4};
    cout << a.takeCoins(nums);
    return 0;
}