#include <iostream>
#include <vector>
#include <list>

using namespace std;


vector<int> reconstructQueue(vector<pair<int, int>>& heights) {
    //pair.first is height
    //pair.second is how many people are taller ahead
    sort(heights.begin(), heights.end(), [](decltype(*heights.begin())& lhs, pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    });
    vector<int> result;
    for (auto height : heights) {
        result.insert(result.begin() + height.second, height.first);
    }
    return result;
}


int main() {
    vector<pair<int, int>> heights{{3,2}, {4,0}, {4,0}, {4,0}, {4,0}};
    auto result = reconstructQueue(heights);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}