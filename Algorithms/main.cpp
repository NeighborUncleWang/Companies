#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void countingSort(vector<int>& nums) {
    vector<int> count(11, 0);
    for (int num : nums) {
        ++count[num];
    }
    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    int n = nums.size();
    vector<int> output(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        output[count[nums[i]] - 1] = nums[i];
        --count[nums[i]];
    }
    move(output.begin(), output.end(), nums.begin());
}

int main() {
    vector<int> nums{0,1,3,2,4,5};
    countingSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}