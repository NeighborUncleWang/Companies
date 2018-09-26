#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> FindPath(string file_name) {
        ifstream ifs(file_name);
        string temp;
        getline(ifs, temp);
        auto it = temp.find(' ');
        string source = temp.substr(0, it);
        string destination = temp.substr(it + 1);
        unordered_map<string, unordered_set<string>> adj_list;
        string line;
        while (getline(ifs, line)) {
            auto it = line.find(':');
            string cur = line.substr(0, it - 1);
            stringstream ss(line.substr(it + 2));
            string neighbor;
            while (ss >> neighbor) {
                adj_list[cur].insert(neighbor);
            }
        }
        vector<string> res;
        unordered_set<string> visited;
        string path;
        dfs(source, destination, source, visited, adj_list, path, res);
        return res;
    }
    
    vector<string> parseLines(const vector<string>& lines) {
        string temp = lines.front();
        auto it = temp.find(' ');
        string source = temp.substr(0, it);
        string destination = temp.substr(it + 1);
        unordered_map<string, unordered_set<string>> adj_list;
        for (int i = 1; i < lines.size(); ++i) {
            auto it = lines[i].find(':');
            string cur = lines[i].substr(0, it - 1);
            stringstream ss(lines[i].substr(it + 2));
            string neighbor;
            while (ss >> neighbor) {
                adj_list[cur].insert(neighbor);
            }
        }
        vector<string> res;
        unordered_set<string> visited;
        string path;
        dfs(source, destination, source, visited, adj_list, path, res);
        return res;
    }

private:
    void dfs(string& source, string& destination, string cur, unordered_set<string>& visited,
             unordered_map<string, unordered_set<string>>& adj_list, string& path, vector<string>& res) {
        if (cur == destination) {
            int size = path.size();
            path += destination;
            res.push_back(path);
            path.resize(size);
            return;
        }
        visited.insert(cur);
        int size = path.size();
        path += cur;
        for (auto& neighbor : adj_list[cur]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(source, destination, neighbor, visited, adj_list, path, res);
            }
        }
        path.resize(size);
        visited.erase(cur);
    }
};

int main() {
    Solution a;
    auto res = a.FindPath("input_1.txt");
    for (auto it : res) {
        cout << it << endl;
    }
    return 0;
}