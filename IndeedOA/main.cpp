#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

class Solution {
private:
    //the problem mentioned that vi and ci values are integers
    //I was thinking about using long long
    map<int, int> hashMap;
public:
    vector<int> CalculatingQuantiles(void) {
        int Q = 0;
        int M = 0;
        cin >> Q >> M;
        long long totalCount = 0;
        for (int i = 0; i < M; ++i) {
            int vi = 0;
            int ci = 0;
            cin >> vi >> ci;
            hashMap[vi] = ci;
            totalCount += ci;
        }
        vector<int> result;
        auto iterator = hashMap.begin();
        long long currentCount = iterator->second;
        for (int k = 1; k < Q; ++k) {
            int Ik = ceil(totalCount * k * 1.0 / Q);
            if (currentCount >= Ik) {
                result.push_back(iterator->first);
            } else {
                while (currentCount < Ik) {
                    ++iterator;
                    currentCount += iterator->second;
                }
                result.push_back(iterator->first);
            }
        }
        for (int q : result) {
            cout << q << endl;
        }
        return result;
    }
};


int main() {

    return 0;
}