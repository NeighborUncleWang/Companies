#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodingsWithStar(string s) {
        if (s.empty()) return 0;
        int fn_2 = 1, fn_1 = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); ++i) {
            int cur = 0;
            if (s[i] == '*') {
                cur = 9 * fn_1;
            } else {
                cur = s[i] == '0' ? 0 : fn_1;
            }
            if (s[i] == '*' && s[i - 1] == '*') {
                cur += 17 * fn_2;
            } else if (s[i] == '*') {
                if (s[i - 1] == '1') {
                    cur += 10 * fn_2;
                } else if (s[i - 1] == '2') {
                    cur += 7 * fn_2;
                }
            } else if (s[i - 1] == '*') {
                if (s[i] <= '6') {
                    cur += 2 * fn_2;
                } else {
                    cur += fn_2;
                }
            } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                cur += fn_2;
            }
            fn_2 = fn_1;
            fn_1 = cur;
        }
        return fn_1;
    }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}