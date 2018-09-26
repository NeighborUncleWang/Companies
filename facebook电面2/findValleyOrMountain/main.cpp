#include <iostream>
#include <vector>

using namespace std;


int FindValleyOrMountain(const vector<int>& nums) {
    return 0.5 * ((nums[1] > nums[0] ? nums.back() - nums[0] : nums[0] - nums.back()) + nums.size() - 1);
}

int main() {
    vector<int> nums{1,2,3,4,3,2,1};
    cout << FindValleyOrMountain(nums) << endl;
    nums = vector<int>{6,5,4,3,2,3,4};
    cout << FindValleyOrMountain(nums) << endl;
    return 0;
}