#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

int main() {
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
                for (auto& it : prefixes_map[child]) {
                    prefixes_map[parent][it.first] += it.second;
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
        cout << prefixes_map[topic][query.substr(it + 1)] << endl;
    }
    return 0;
}