#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    bool CanPartitionSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (n < k) {
            return false;
        } else if (sum % k != 0) {
            return false;
        }
        vector<int> sums(k, 0);
        vector<int> filled(k, 0);
        return helper(nums, sums, filled, 0, sum / k);
    }

private:
    bool helper(vector<int>& nums, vector<int>& sums, vector<int>& filled, int index, int target) {
        if (index == nums.size()) {
            for (int i = 0; i < sums.size(); ++i) {
                if (filled[i] == 0 || sums[i] != target) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] += nums[index];
            ++filled[i];
            if (helper(nums, sums, filled, index + 1, target)) {
                return true;
            }
            sums[i] -= nums[index];
            --filled[i];
        }
    }
};


int main() {
    Solution a;
    vector<int> nums{2, 1, 4, 5, 6};
    cout << a.CanPartitionSubsetSum(nums, 3) << endl;
    nums = vector<int>{2, 1, 5, 5, 6};
    cout << a.CanPartitionSubsetSum(nums, 3) << endl;
    nums = vector<int>{2, 1, 4, 5, 3, 3};
    cout << a.CanPartitionSubsetSum(nums, 3) << endl;
    return 0;
}