#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string rearrange(string& str, int k) {
        unordered_map<char, int> hashMap;
        for (char ch : str) {
            ++hashMap[ch];
        }
        vector<pair<char, int>> temp(hashMap.begin(), hashMap.end());
        sort(temp.begin(), temp.end(), [](pair<char, int> lhs, pair<char, int> rhs) {
            return lhs.second > rhs.second;
        });
        vector<vector<char>> buckets(temp.front().second);
        int index = 0;
        for (auto& entry : temp) {
            for (int i = 0; i < entry.second; ++i) {
                buckets[index++].push_back(entry.first);
                if (index == buckets.size()) {
                    index = 0;
                }
            }
        }
        int size = buckets.size();
        if (buckets[size - 1].size() < k) return "";
        string result;
        for (auto& bucket : buckets) {
            result.insert(result.end(), bucket.begin(), bucket.end());
        }
        return result;
    }
};

int main() {
    Solution a;
    string s = "aaaabbbcc";
    cout << a.rearrange(s, 2);
    return 0;
}