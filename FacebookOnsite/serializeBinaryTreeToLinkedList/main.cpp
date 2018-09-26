#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct Solution {
    ListNode* convertBTMorris(TreeNode* root) {
        ListNode dummyNode(0);
        ListNode* dummy = &dummyNode;
        ListNode* iter = dummy;
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left) {
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == current) {
                    iter->next = new ListNode(current->val);
                    iter = iter->next;
                    predecessor->right = nullptr;
                    current = current->right;
                } else {
                    predecessor->right = current;
                    current = current->left;
                }
            } else {
                iter->next = new ListNode(current->val);
                iter = iter->next;
                current = current->right;
            }
        }
        return dummy->next;
    }
    ListNode* convertBTRecursive(TreeNode* root) {
        ListNode dummyNode(-1);
        ListNode* dummy = &dummyNode;
        ListNode* iter = dummy;
        dfs(iter, root);
        return dummy->next;
    }
    void dfs(ListNode*& iter, TreeNode* current) {
        if (current == nullptr) return;
        dfs(iter, current->left);
        iter->next = new ListNode(current->val);
        iter = iter->next;
        dfs(iter, current->right);
    }
    ListNode* convertBTIterative(TreeNode* root) {
        ListNode dummyNode(-1);
        ListNode* dummy = &dummyNode;
        ListNode* iter = dummy;
        stack<TreeNode*> st;
        TreeNode* current = root;
        while (!st.empty() || current) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                iter->next = new ListNode(current->val);
                iter = iter->next;
                current = current->right;
            }
        }
        return dummy->next;
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
    auto head = a.convertBTMorris(root);
    auto iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;
    head = a.convertBTRecursive(root);
    iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;
    head = a.convertBTIterative(root);
    iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    return 0;
}