#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool nonnegativeVersion(vector<int>& nums, int target) {
//        if (target < 0) return false;
        int sum = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            if (sum == target) {
                return true;
            } else {
                while (left <= right && sum > target) {
                    sum -= nums[left++];
                }
            }
        }
        return false;
    }
    bool containsNegative(vector<int>& nums, int target) {
        unordered_set<int> hashSet{0};
        int sum = 0;
        for (int num : nums) {
            sum += num;
            if (hashSet.find(sum - target) != hashSet.end()) {
                return true;
            } else {
                hashSet.insert(sum);
            }
        }
        return false;
    }
};


int main() {
    Solution a;
    vector<int> nums{100,0,0,1,2,3};
    cout << a.nonnegativeVersion(nums, 1) << endl;
    vector<int> nums2{100, -1, -10, 2, 20, 5};
    cout << a.containsNegative(nums2, -7) << endl;
    return 0;
}