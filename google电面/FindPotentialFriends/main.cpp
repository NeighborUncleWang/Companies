#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class SocialNetwork {
private:
    unordered_map<string, unordered_set<string>> adjList;
public:
    SocialNetwork(vector<pair<string, string>>& edges) {
        for (auto& edge : edges) {
            adjList[edge.first].insert(edge.second);
            adjList[edge.second].insert(edge.first);
        }
    }
    vector<string> FindPotentialFriends(string name) {
        queue<string> nodesQueue;
        vector<string> result;
        unordered_map<string, int> countsPeople;
        unordered_map<string, bool> visited;
        visited[name] = true;
        for (auto& neighbor : adjList[name]) {
            if (visited[neighbor] == bool{}) {
                nodesQueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
        while (!nodesQueue.empty()) {
            auto current = nodesQueue.front();
            nodesQueue.pop();
            for (auto& neighbor : adjList[current]) {
                if (visited[neighbor] == false) {
//                    cout << neighbor << endl;
                    ++countsPeople[neighbor];
                }
            }
        }
        vector<pair<string, int>> temp(countsPeople.begin(), countsPeople.end());
//        sort(temp.begin(), temp.end(),
//             [](pair<const string, int>& lhs, pair<const string, int>& rhs) { return lhs.second > rhs.second; });
        sort(temp.begin(), temp.end(),
             [](pair<string, int>& lhs, pair<string, int>& rhs) { return lhs.second > rhs.second; });
        for (auto& people : temp) {
            result.push_back(people.first);
        }
        return result;
    };
};

int main() {
    vector<pair<string, string>> edges{
            {"xianshu", "haha"},
            {"xianshu", "taotao"},
            {"xianshu", "baobao"},
            {"xianshu", "pingping"},
            {"haha", "laowang"},
            {"taotao", "laowang"},
            {"baobao", "laowang"},
            {"pingping", "laowang"},
            {"haha", "wangqi"},
            {"taotao", "wangqi"},
            {"baobao", "wangqi"},
            {"haha", "chuang"},
            {"taotao", "chuang"},
    };
    SocialNetwork a(edges);
    auto result = a.FindPotentialFriends("xianshu");
    for (string& s : result) {
        cout << s << endl;
    }
    //result should be "laowang", "wangqi", "chuang"
    return 0;
}