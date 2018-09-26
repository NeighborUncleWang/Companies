#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

struct TrieNode {
    bool is_word = false;
    vector<TrieNode*> children;
    int starts_with;
    TrieNode() : children(256, nullptr), starts_with(0) {}
};
struct Trie {
    TrieNode* root = new TrieNode();
    void AddString(string word) {
        auto current = root;
        for (char ch : word) {
            if (current->children[ch] == nullptr) {
                current->children[ch] = new TrieNode();
            }
            ++current->starts_with;
            current = current->children[ch];
        }
        current->is_word = true;
        ++current->starts_with;
    }
    int GetStartsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children[ch] == nullptr) {
                return 0;
            }
            current = current->children[ch];
        }
        return current->starts_with;
    }
};




#define DEBUG
int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
#endif
    int topic_num;
    cin >> topic_num;
    string topic_string;
    cin.ignore();
    getline(cin, topic_string);
    int question_num;
    cin >> question_num;
    cin.ignore();
    unordered_map<string, Trie> prefixes_map;
    unordered_map<string, vector<string>> questions_map;
    string question;
    for (int i = 0; i < question_num; ++i) {
        getline(cin, question);
        auto it = question.find(':');
        string topic = question.substr(0, it);
        //by pass the ':' and the ' '
        it += 2;
        //store the number of each prefix corresponding to the topic name
        prefixes_map[topic].AddString(question.substr(it));
        questions_map[topic].push_back(question.substr(it));
    }
    string temp;
    stack<string> st;
    stringstream ss(topic_string);
    while (ss >> temp) {
        if (temp != ")") {
            st.push(temp);
        } else {
            vector<string> children;
            while (st.top() != "(") {
                string cur = st.top();
                st.pop();
                children.push_back(cur);
            }
            st.pop();//pop "("
            string parent = st.top();
            for (string& child : children) {
                for (auto& s : questions_map[child]) {
                    questions_map[parent].push_back(s);
                    prefixes_map[parent].AddString(s);
                }
            }
        }
    }
    //handle query
    int query_num;
    cin >> query_num;
    cin.ignore();
    string query;
    while (getline(cin, query)) {
        auto it = query.find(' ');
        string topic = query.substr(0, it);
        cout << prefixes_map[topic].GetStartsWith(query.substr(it + 1)) << endl;
    }
    return 0;
}