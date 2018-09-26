#include <iostream>
#include <vector>

using namespace std;

int FindTarget(vector<int>& nums, int target) {
    int low = 0;
    int size = nums.size();
    int high = size - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (nums[middle] <= target) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return high;
}

int main() {
    vector<int> nums{1,2,3,3,3,3,5,6,7};
    //right solution is 5
    cout << FindTarget(nums, 3);
    return 0;
}