#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //if requires >= [n/4]
    vector<int> findMajorityInSortedArray(vector<int>& nums) {
        int size = nums.size();
        int leastCount = size / 4 + 1;
        vector<int> result;
        //[leftBoundary, rightBoundary)
        for (int i = leastCount - 1; i < size; i += leastCount) {
            int leftBoundary = binarySearch(nums, nums[i]);
            int rightBoundary = binarySearch(nums, nums[i] + 1);
            cout << "left" << leftBoundary << endl;
            cout << "right" << rightBoundary << endl;
            int count = rightBoundary - leftBoundary;
            cout << "count= " << count << endl;
            if (count >= leastCount) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
private:
    int binarySearch(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] >= target) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution a;
    vector<int> nums{1,1,1,1,2,2,2,3,3,3,4,4,4};
    auto result = a.findMajorityInSortedArray(nums);
    for (int i : result) {
        cout << i << endl;
    }
    return 0;
}