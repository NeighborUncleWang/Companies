#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct Solution {
    TreeNode* SerializeMorris(TreeNode* root) {
        TreeNode dummyNode(-1);
        TreeNode* dummy = &dummyNode;
        TreeNode* current = root;
        TreeNode* iter = dummy;
        while (current) {
            if (current->left) {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
//                    cout << current->val << " ";
                    iter->right = current;
                    current->left = iter;
                    iter = iter->right;
                    current = current->right;
                }
            } else {
//                cout << current->val << " ";
                iter->right = current;
                current->left = iter;
                iter = iter->right;
                current = current->right;
            }
        }
        return dummy->right;
    }
    TreeNode* SerializeRecursive(TreeNode* root) {
        TreeNode dummyNode(-1);
        TreeNode* dummy = &dummyNode;
        TreeNode* iter = dummy;
        dfs(iter, root);
        return dummy->right;
    }
    void dfs(TreeNode*& iter, TreeNode* current) {
        if (current == nullptr) return;
        dfs(iter, current->left);
        iter->right = current;
        current->left = iter;
        iter = iter->right;
        dfs(iter, current->right);
    }
    TreeNode* SerializeIterative(TreeNode* root) {
        TreeNode dummyNode(-1);
        TreeNode* dummy = &dummyNode;
        TreeNode* iter = dummy;
        stack<TreeNode*> st;
        TreeNode* current = root;
        while (!st.empty() || current != nullptr) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                iter->right = current;
                current->left = iter;
                iter = iter->right;
                current = current->right;
            }
        }
        return dummy->right;
    }
};

int main() {
    Solution a;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    auto head = a.SerializeMorris(root);
    auto iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->right;
    }
    cout << endl;
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(8);
    root2->right->left = new TreeNode(7);
    root2->right->right = new TreeNode(9);
    head = a.SerializeRecursive(root2);
    iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->right;
    }
    cout << endl;
    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(3);
    root3->left->left = new TreeNode(2);
    root3->left->right = new TreeNode(4);
    root3->right = new TreeNode(8);
    root3->right->left = new TreeNode(7);
    root3->right->right = new TreeNode(9);
    head = a.SerializeRecursive(root3);
    iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->right;
    }
    return 0;
}