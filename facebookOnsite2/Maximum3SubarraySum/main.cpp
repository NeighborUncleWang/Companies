#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int Find3Window(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int max_sum = sum;
        dp[0][k - 1] = sum;
        for (int i = k; i < n; ++i) {
            sum = sum - nums[i - k] + nums[i];
            max_sum = max(max_sum, sum);
            dp[0][i] = max_sum;
        }
        sum = 0;
        for (int i = k; i < 2 * k; ++i) {
            sum += nums[i];
        }
        max_sum = sum;
        dp[1][2 * k - 1] = sum + dp[0][k - 1];
        cout << dp[1][2*k-1] << endl;
        for (int i = 2 * k; i < n; ++i) {
            sum = sum - nums[i - k] + nums[i];
            max_sum = max(max_sum, sum);
            dp[1][i] = max_sum + dp[0][i - k];
        }
        sum = 0;
        for (int i = 2 * k; i < 3 * k; ++i) {
            sum += nums[i];
        }
        max_sum = sum;
        dp[2][3 * k - 1] = sum + dp[1][2 * k - 1];
        for (int i = 3 * k; i < n; ++i) {
            sum = sum - nums[i - k] + nums[i];
            max_sum = max(max_sum, sum);
            dp[2][i] = max_sum + dp[1][i - k];
        }
        return dp.back().back();
    }
    int FindNWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int i = 0; i < 3; ++i) {
            int sum = 0;
            for (int j = i; j < (i + 1) * k; ++j) {
                sum += nums[j];
            }
            int max_sum = sum;
            dp[i][(i + 1) * k - 1] = (i == 0 ? 0 : dp[i - 1][i * k - 1]) + sum;
            for (int j = (i + 1) * k; j < n; ++j) {
                sum = sum - nums[j - k] + nums[j];
                max_sum = max(max_sum, sum);
                dp[i][j] = max_sum + (i == 0 ? 0 : dp[i - 1][j - k]);
            }
        }
        return dp.back().back();
    }
};


int main() {
    Solution a;
    vector<int> nums{1,2,1,2,6,7,5,1};
    cout << accumulate(nums.begin(), nums.end(), 0) << endl;
    cout << a.FindNWindow(nums, 2) << endl;
    return 0;
}