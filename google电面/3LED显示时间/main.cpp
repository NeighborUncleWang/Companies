#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findTimes() {
        //4 bits for hours
        //6 bits for minutes
        vector<string> result;
        for (int i = 0; i < 10 - 2; ++i) {
            for (int j = i + 1; j < 10 - 1; ++j) {
                for (int k = j + 1; k < 10; ++k) {
                    int value = 0;
                    value |= (1 << i) | (1 << j) | (1 << k);
                    int hours = value >> 6;
                    int minutes = value & 0x3F;
                    if (hours <= 11 && minutes <= 59) {
                        result.push_back(to_string(hours) + ":" + to_string(minutes));
                    }
                }
            }
        }
        return result;
    }
    vector<string> FindKTimes(int k) {
        if (k == 0) return vector<string>();
        vector<string> result;
        helper(0, k, 0, result);
        return result;
    }
private:
    void helper(int start, int k, int value, vector<string>& result) {
        if (k == 0) {
            int hours = value >> 6;
            int minutes = value & 0x3F;
            if (hours <= 11 && minutes <= 59) {
                result.push_back(to_string(hours) + ":" + to_string(minutes));
            }
            return;
        }
        for (int i = start; i < 10 - k + 1; ++i) {
            helper(i + 1, k - 1, value | (1 << i), result);
        }
    }
};


int main() {
    Solution a;
//    auto result = a.findTimes();
//    cout << "Total number: " << result.size() << endl;
//    for (string& s : result) {
//        cout << s << endl;
//    }
    auto resultk = a.FindKTimes(1);
    cout << "Total number: " << resultk.size() << endl;
    for (string& s : resultk) {
        cout << s << endl;
    }
    return 0;
}