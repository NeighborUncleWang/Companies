#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> PrintPath(vector<string>& stops) {
        vector<string> res;
        string path;
        path.push_back(stops.front().front());
        Helper(res, stops, 1, path);
        return res;
    }
private:
    void Helper(vector<string>& res, vector<string>& stops, int index, string& path) {
        if (index == stops.size() - 1) {
            path.push_back(stops.back().front());
            res.push_back(path);
            path.pop_back();
            return;
        }
        for (char ch : stops[index]) {
            Helper(res, stops, index + 1, path);
            path.push_back(ch);
            Helper(res, stops, index + 1, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution a;
    vector<string> stops{"X", "AB", "CDE", "Y"};
    auto res = a.PrintPath(stops);
    int count = 0;
    for (auto& i : res) {
        cout << count++ << " ";
        cout << i << endl;
    }
    return 0;
}