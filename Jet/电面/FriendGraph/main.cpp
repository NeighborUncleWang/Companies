#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct Person {
    int id;
    string name;
    string role;
    Person(int id, string name, string role) {
        this->id = id;
        this->name = name;
        this->role = role;
    }
};


class Solution {
private:
    unordered_map<int, unordered_set<int>> adj_list;
    unordered_map<int, string> names;
    unordered_map<int, string> roles;
public:
    void OutputList(vector<string>& employees, vector<string>& friends) {
        for (auto& employee : employees) {
            auto it1 = employee.find(',');
            auto it2 = employee.find(',', it1 + 1);
            int id = stoi(employee.substr(0, it1));
            string name = employee.substr(it1 + 1, it2 - it1 - 1);
            string role = employee.substr(it2 + 1);
            Person p = Person(id, name, role);
            cout << id << endl;
            cout << name << endl;
            cout << role << endl;
            set.insert(p);
        }
        for (auto& relation : friends) {
            auto it = relation.find(',');
            int id1 = stoi(relation.substr(0, it));
            int id2 = stoi(relation.substr(it + 1));
            adj_list[id1].insert(id2);
            adj_list[id2].insert(id1);
        }
//        for (auto& it : adj_list) {
//            cout << map[it.first].name;
//        }
    }
};


int main() {
    Solution a;
    vector<string> employees{"1,Alice,HR", "2,Bob,Engineer"};
    vector<string> friends{"1,2"};
    a.OutputList(employees, friends);
    return 0;
}