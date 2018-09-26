#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>
#include <unordered_set>

using namespace std;

int dfs(string& cur, string& prefix, unordered_map<string, unordered_map<string, int>>& prefixes_map,
        unordered_map<string, vector<string>>& children_map, unordered_map<string, unordered_set<string>>& visited) {
    if (visited.count(cur) && visited[cur].count(prefix)) {
        return prefixes_map[cur][prefix];
    }
    visited[cur].insert(prefix);
    int res = prefixes_map[cur][prefix];
    if (children_map.count(cur) != 0) {
        for (string& child : children_map[cur]) {
            res += dfs(child, prefix, prefixes_map, children_map, visited);
        }
    }
    return prefixes_map[cur][prefix] = res;
}

//#define DEBUG
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
    unordered_map<string, unordered_map<string, int>> prefixes_map;
    string question;
    for (int i = 0; i < question_num; ++i) {
        getline(cin, question);
        auto it = question.find(':');
        string topic = question.substr(0, it);
        //by pass the ':' and the ' '
        it += 2;
        //store the number of each prefix corresponding to the topic name
        for (int end = it; end < question.size(); ++end) {
            ++prefixes_map[topic][question.substr(it, end - it + 1)];
        }
    }
    string temp;
    stack<string> st;
    //process the topic string
    stringstream ss(topic_string);
    unordered_map<string, vector<string>> children_map;
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
            //merge the prefixes count from children to their parent
            for (string& child : children) {
                children_map[parent].push_back(child);
            }
        }
    }
    //handle query
    int query_num;
    cin >> query_num;
    cin.ignore();
    string query;
    unordered_map<string, unordered_set<string>> visited;
    while (getline(cin, query)) {
        auto it = query.find(' ');
        string topic = query.substr(0, it);
        string prefix = query.substr(it + 1);
        cout << dfs(topic, prefix, prefixes_map, children_map, visited) << endl;
    }
    return 0;
}