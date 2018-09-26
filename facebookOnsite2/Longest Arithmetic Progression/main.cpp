#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int LLAP(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
//        for (int j = n - 1; j > 0; --j) {
//            int i = j - 1, k = j + 1;
//            while (i >= 0 && k < n) {
//                if (nums[i] + nums[k] == nums[j] * 2) {
//                    dp[i][j] = dp[j][k] == 0 ? 3 : (dp[j][k] + 1);
//                    res = max(dp[i][j], res);
//                    --i;
//                    ++k;
//                } else if (nums[i] + nums[k] < nums[j] * 2) {
//                    ++k;
//                } else {
//                    --i;
//                }
//            }
//        }
        for (int j = 0; j < n - 1; ++j) {
            int i = j - 1, k = j + 1;
            while (i >= 0 && k < n) {
                if (nums[i] + nums[k] == nums[j] * 2) {
                    dp[j][k] = dp[i][j] == 0 ? 3 : (dp[i][j] + 1);
                    res = max(dp[j][k], res);
                    --i;
                    ++k;
                } else if (nums[i] + nums[k] < nums[j] * 2) {
                    ++k;
                } else {
                    --i;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> nums{1, 7, 10, 15, 27, 29};
    cout << a.LLAP(nums) << endl;
    nums = vector<int>{5, 10, 15, 20, 25, 30};
    cout << a.LLAP(nums) << endl;
    return 0;
}