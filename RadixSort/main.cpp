#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& nums, int base) {
    vector<int> count(10, 0);
    for (int num : nums) {
        ++count[num / base % 10];
    }
    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    vector<int> output(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
        output[count[nums[i] / base % 10] - 1] = nums[i];
        --count[nums[i] / base % 10];
    }
    nums = move(output);
}

void radixSort(vector<int>& nums) {
    int range = *max_element(nums.begin(), nums.end());
    for (int base = 1; range / base; base *= 10) {
        countingSort(nums, base);
    }
}

int main() {
    vector<int> nums{170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}