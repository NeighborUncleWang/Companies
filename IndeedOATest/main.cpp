#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<int, int> hashMap;
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
    auto iterator = hashMap.begin();
    long long currentCount = iterator->second;
    for (int k = 1; k < Q; ++k) {
        int Ik = ceil(totalCount * k * 1.0 / Q);
        if (currentCount >= Ik) {
            cout << iterator->first;
        } else {
            while (currentCount < Ik) {
                ++iterator;
                currentCount += iterator->second;
            }
            cout << iterator->first;
        }
    }
    return 0;
}