#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <list>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) { };
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelection(nums, 0, (int)nums.size() - 1, k);
    }
private:
    int quickSelection(vector<int>& nums, int start, int end, int k) {
        if (end == start) {
            return nums[start];
        }
        int pivot = partition(nums, start, end);
        int order = pivot - start + 1;
        if (order == k) {
            return nums[order];
        } else if (order < k) {
            return quickSelection(nums, pivot + 1, end, k - order);
        } else {
            return quickSelection(nums, start, pivot - 1, k);
        }
    }
    int partition(vector<int>& nums, int start, int end) {
        int val = nums[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (nums[j] >= val) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end]);
        return i + 1;
    }
};

int main() {
    Solution a;
    vector<int> nums{2, 1};
    cout << a.findKthLargest(nums, 2);
    return 0;
}