#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isWord = false;
};

class Solution {
public:
    vector<string> letterCombinations(string digits, vector<string>& dicts) {
        if (digits.empty()) return vector<string>();
        for (string& s : dicts) {
            AddString(s);
        }
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string comb;
        helper(digits, 0, res, comb, dict, root);
        return res;
    }
private:
    TrieNode* root = new TrieNode();
    void AddString(const string& word) {
        auto current = root;
        for (char ch : word) {
            if (current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isWord = true;
    }
    void helper(string digits, int index, vector<string>& res, string& comb, vector<string>& dict, TrieNode* cur) {
        if (index == digits.size() && cur && cur->isWord) {
            res.push_back(comb);
            return;
        }
        for (char ch : dict[digits[index] - '0']) {
            if (cur->children[ch - 'a']) {
                comb.push_back(ch);
                helper(digits, index + 1, res, comb, dict, cur->children[ch - 'a']);
                comb.pop_back();
            }
        }
    }
};

int main() {
    Solution a;
    vector<string> dict{"ad", "af", "bd"};
    auto res = a.letterCombinations("23", dict);
    for (auto& s : res) {
        cout << s << endl;
    }
    return 0;
}