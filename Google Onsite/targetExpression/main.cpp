#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> targetExpression(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<string> result;
        vector<bool> used(nums.size(), false);
        dfs(nums, result, used, "", 0, 0, 0, target);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<string>& result, vector<bool>& used, string expression,
             long long leftVal, long long leftNum, int index, int target) {
        if (index == nums.size() && leftVal == target) {
            result.push_back(expression);
            return;
        } else if (index == nums.size()) {
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (!used[i]) {
                used[i] = true;
                if (index == 0) {
                    dfs(nums, result, used, to_string(nums[i]), nums[i], nums[i], index + 1, target);
                } else {
                    string currentNum = to_string(nums[i]);
                    dfs(nums, result, used, expression + "+" + currentNum, leftVal + nums[i], nums[i], index + 1, target);
                    dfs(nums, result, used, expression + "-" + currentNum, leftVal - nums[i], -nums[i], index + 1, target);
                    dfs(nums, result, used, expression + "*" + currentNum, leftVal - leftNum + leftNum * nums[i],
                    leftNum * nums[i], index + 1, target);
                    dfs(nums, result, used, expression + "/" + currentNum, leftVal - leftNum + leftNum / nums[i],
                    leftNum / nums[i], index + 1, target);
                }
                used[i] = false;
            }
        }
    }
};


class Solution2 {
public:
    bool targetExpression(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<string> result;
        vector<bool> used(nums.size(), false);
        return dfs(nums, used, 0, 0, 0, target);
    }
private:
    bool dfs(vector<int>& nums, vector<bool>& used,
             long long leftVal, long long leftNum, int index, int target) {
        if (index == nums.size() && leftVal == target) {
            return true;
        } else if (index == nums.size()) {
            return false;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (!used[i]) {
                used[i] = true;
                if (index == 0) {
                    return dfs(nums, used, nums[i], nums[i], index + 1, target);
                } else {
                    string currentNum = to_string(nums[i]);
                    if (dfs(nums, used, leftVal + nums[i], nums[i], index + 1, target)) return true;
                    if (dfs(nums, used, leftVal - nums[i], -nums[i], index + 1, target)) return true;
                    if (dfs(nums, used, leftVal - leftNum + leftNum * nums[i],
                            leftNum * nums[i], index + 1, target)) return true;
                    if (dfs(nums, used, leftVal - leftNum + leftNum / nums[i],
                        leftNum / nums[i], index + 1, target)) return true;
                }
                used[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums{2,2};
    Solution a;
    auto result = a.targetExpression(nums, 4);
    for (string& exp : result) {
        cout << exp << endl;
    }
    Solution2 s;
    cout << s.targetExpression(nums, 60);
    return 0;
}