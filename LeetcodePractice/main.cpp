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


int main() {
    Solution a;
    vector<int> nums{2, 1};
    cout << a.findKthLargest(nums, 2);
    return 0;
}