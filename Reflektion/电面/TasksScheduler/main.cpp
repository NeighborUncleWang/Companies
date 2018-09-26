#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool CanAssign(vector<int> tasks, vector<int> servers) {
    for (int i = 0; i < tasks.size(); ++i) {
        for (int j = 0; j < servers.size(); ++j) {
            if (servers[j] > 0) {
                --servers[j];
                --tasks[i];
            }
            if (tasks[i] == 0) {
                break;
            }
        }
        if (tasks[i] > 0) {
            return false;
        }
    }
    return true;
}
bool CanAssign2(vector<int> tasks, vector<int> servers) {
    queue<int> q;
    for (int server : servers) {
        q.push(server);
    }
    for (int task : tasks) {
        if (task > q.size()) {
            return false;
        }
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto cur = q.front();
            q.pop();
            --cur;
            --task;
            if (cur > 0) {
                q.push(cur);
            }
            if (task == 0) break;
        }
        if (task > 0) return false;
    }
    return true;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}