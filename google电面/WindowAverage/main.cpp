#include <iostream>
#include <vector>

using namespace std;


vector<double> WindowAverage(vector<int>& nums, int winSize) {
    int size = nums.size();
    int left = 0;
    int right = 0;
    vector<double> result;
    int sum = 0;
    for (; right < winSize; ++right) {
        sum += nums[right];
    }
    result.push_back(sum * 1.0 / winSize);
    for (; right < size; ++right) {
        sum+= nums[right];
        sum-= nums[left++];
        result.push_back(sum * 1.0 / winSize);
    }
    return result;
}

int main() {
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    vector<double> result = WindowAverage(nums, 10);
    cout << result.size() << endl;
    for (double i : result) {
        cout << i << " ";
    }
    return 0;
}