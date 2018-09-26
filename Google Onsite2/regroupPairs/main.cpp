#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool pairCompare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first< b.first;
}
int reGroup(vector<pair<int, int>> in,vector<int> counts,
            vector<vector<pair<int, int>>> &ret)
{
    int n = in.size(),m = counts.size();
    sort(in.begin(),in.end(), pairCompare);
    ret.resize(m);
    for(int i=1; i< m; ++i){
        counts[i] += counts[i-1];
    }
    int j = 0;
    for(int i=0;i<n; ++i){
        int key =in[i].first;
        while(key>= counts[j]) {
            ++j;
            if(j >= m) {
                cout<< "Illegal input." << endl;
                return-1;
            }
        }
        cout <<key << "\tgroup=" << j << endl;
        if(j >0)  in[i].first -= counts[j-1];
        ret[j].push_back(in[i]);
    }
    return 0;
}
int main() {
    vector<pair<int, int>> in = {{0, 6},
                                 {4, 92},
                                 {5, 7},
                                 {6, 10},
                                 {15, 0},
                                 {19, 2}
    };
    vector<int>counts = {5, 10, 5};
    vector<vector<pair<int, int>>> ret;
    if(reGroup(in,counts, ret) == 0) {
        for (auto&v : ret) {
            cout<< endl;
            for (auto &p : v) {
                cout<< "(" << p.first << ", " <<p.second << ")" << endl;
            }
        }
    }
    return 0;
}