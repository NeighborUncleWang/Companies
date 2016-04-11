#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> slidingWindowAverage(vector<int>& nums, int k) {
        vector<double> result;
        int sum = 0;
        for (int left= 0, right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            if (right - left + 1 >= k) {
                result.push_back(sum * 1.0 / k);
                sum -= nums[left++];
            }
        }
        return result;
    }
};

int main() {
    Solution a;
    vector<int> nums{2,4,6,8,10};
    auto result = a.slidingWindowAverage(nums, 3);
    for (double i : result) {
        cout << i << " ";
    }
    return 0;
}