#include <iostream>
#include <vector>

using namespace std;

//Reference
//http://www.geeksforgeeks.org/counting-sort/

void countingSort(vector<int>& nums) {
    int range = *max_element(nums.begin(), nums.end());
    vector<int> count(range + 1, 0);
    for (int num : nums) {
        ++count[num];
    }
    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    vector<int> output(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
        output[count[nums[i]] - 1] = nums[i];
        --count[nums[i]];
    }
    nums = move(output);
}


int main() {
    vector<int> nums{1,2,3,4,15,13,11,9,7,5,0};
    countingSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}