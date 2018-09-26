#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int FindLast(int start, vector<int>& nums) {
    int num = nums[start];
    int diff = 1;
    while (start + diff < nums.size() && nums[start + diff] == num) {
        diff *= 2;
    }
    if (start + diff >= nums.size()) {
        return nums.size() - 1;
    }
    int end = start + diff;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == num) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

unordered_map<int, int> GroupNumber(vector<int>& nums) {
    unordered_map<int, int> res;
    for (int start = 0; start < nums.size(); ) {
        int end = FindLast(start, nums);
        res[nums[start]] = end - start + 1;
        start = end + 1;
    }
    return res;
};

int main() {
    vector<int> nums{1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3};
    auto res = GroupNumber(nums);
    for (auto& it : res) {
        cout << it.first << "," << it.second << endl;
    }
    return 0;
}