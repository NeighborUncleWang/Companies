#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minimumWordLength(vector<string>& dictionary, string& plate) {
        vector<int> hashMap(256, 0);
        int count = 0;
        for (char ch : plate) {
            if (isalpha(ch)) {
                ++hashMap[ch];
                ++count;
            }
        }
        int minLength = INT_MAX;
        int minIndex = 0;
        for (int i = 0; i < dictionary.size(); ++i) {
            for (int right = 0; right < dictionary[i].size(); ++right) {
                if (hashMap[dictionary[i][right]]-- > 0) {
                    --count;
                }
                if (count <= 0 && dictionary[i].size() < minLength) {
                    minLength = dictionary[i].size();
                    minIndex = i;
                }
            }
            for (int right = 0; right < dictionary[i].size(); ++right) {
                if (hashMap[dictionary[i][right]]++ >= 0) {
                    ++count;
                }
            }
        }
        return minLength == INT_MAX ? "" : dictionary[minIndex];
    }
};


int main() {
    Solution a;
    vector<string> dictionary{
            "FFFFFFAAAVX",
            "FFF",
            "FVX",
    };
    string plate = "FVX5077";
    cout << a.minimumWordLength(dictionary, plate);
    return 0;
}