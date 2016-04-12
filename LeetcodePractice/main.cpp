#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <list>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) { };
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long absDividend = llabs(dividend);
        long long absDivisor = llabs(divisor);
        int position = 0;
        while ((absDivisor << 1) <= absDividend) {
            absDivisor <<= 1;
            ++position;
        }
        int result = 0;
        while (absDividend > 0) {
            if (absDividend >= absDivisor) {
                result |= (1 << position);
                absDividend -= absDivisor;
            }
            absDivisor >>= 1;
            --position;
        }
        return isNegative ? -result : result;
    }
};


int main() {
    Solution a;
    a.divide(INT_MIN, -3);
    return 0;
}