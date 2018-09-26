#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> TopDownView(TreeNode* root) {
        if (!root) return vector<int>();
        queue<pair<int, TreeNode*>> q;
        q.emplace(0, root);
        map<int, int> map;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (map.find(cur.first) == map.end()) {
                map[cur.first] = cur.second->val;
            }
            if (cur.second->left) {
                q.emplace(cur.first - 1, cur.second->left);
            }
            if (cur.second->right) {
                q.emplace(cur.first + 1, cur.second->right);
            }
        }
        vector<int> res;
        for (auto& it : map) {
            res.push_back(it.second);
        }
        return res;
    }
    vector<int> BottomView(TreeNode* root) {
        if (!root) return vector<int>();
        queue<pair<int, TreeNode*>> q;
        q.emplace(0, root);
        map<int, int> map;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            map[cur.first] = cur.second->val;
            if (cur.second->left) {
                q.emplace(cur.first - 1, cur.second->left);
            }
            if (cur.second->right) {
                q.emplace(cur.first + 1, cur.second->right);
            }
        }
        vector<int> res;
        for (auto& it : map) {
            res.push_back(it.second);
        }
        return res;
    }
};

int main() {
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->right = new TreeNode(4);
//    root->left->right->right = new TreeNode(5);
//    root->left->right->right->right = new TreeNode(6);
//    Solution a;
//    auto res = a.TopDownView(root);
//    for (int num : res) {
//        cout << num << endl;
//    }

    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    Solution a;
    auto res = a.BottomView(root);
    for (int num : res) {
        cout << num << endl;
    }
    return 0;
}