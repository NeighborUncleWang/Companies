#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//find sums[i] - sums[j] = target
//return (j, i - 1);
//
pair<int, int> findSubarray(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    //sums[i] stores sum of [0, i - 1]
    //sums[0] is always 0
    //sums[1] stores sum of nums[0]
    for (int i = 0; i < n; ++i) {
        sums[i + 1] = sums[i] + nums[i];
    }
    unordered_map<int, int> hashMap;
    for (int i = 0; i <= n; ++i) {
        auto iter = hashMap.find(sums[i] - target);
        if (iter != hashMap.end()) {
            return make_pair(iter->second, i - 1);
        } else {
            hashMap[sums[i]] = i;
        }
    }
    return make_pair(-1, -1);
};


int main() {
    vector<int> nums{-1,-2,-4,-6,-27};
    auto result = findSubarray(nums, -33);
    cout << result.first << " " << result.second;
    return 0;
}